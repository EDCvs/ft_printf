*This project has been created as part of the 42 curriculum by ichimvis.*

# ft_printf

## Description

`ft_printf` is a C project from the 42 curriculum that recreates a subset of the standard `printf` function. Its main goal is to learn how **variadic functions** receive and process arguments, while practicing formatted output, number-base conversion, modular design, and building a static library.

The public interface is:

```c
int ft_printf(const char *format, ...);
```

It writes formatted output to standard output and returns the number of characters printed for supported inputs. The required deliverable is a static archive named `libftprintf.a` at the repository root.

### Supported conversions

| Conversion | Meaning |
| --- | --- |
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer address in hexadecimal |
| `%d`, `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Lowercase hexadecimal integer |
| `%X` | Uppercase hexadecimal integer |
| `%%` | Literal percent sign |

This project implements the mandatory conversions; optional flags, minimum field width, and precision are not implemented.

## Instructions

### Compilation

With the project's source files, `ft_printf.h`, and the `libft/` directory in place, run:

```sh
make
```

The intended result is `libftprintf.a`. The Makefile uses `cc` with `-Wall -Wextra -Werror` and `ar` to create the archive.

| Command | Action |
| --- | --- |
| `make` / `make all` | Build the library |
| `make clean` | Remove compiled object files |
| `make fclean` | Remove object files and the library |
| `make re` | Rebuild from scratch |

**Build status:** The supplied files have not been verified to compile together. Before building, correct the source filenames in the Makefile (`print_pointr.c`, `print_hex.c`, and `print_hex_caps.c` do not match the uploaded filenames), and align the `print_hex_lower` declaration/call with the uploaded implementation, which currently defines `print_hex`. The Makefile expects `libft/Makefile` to build `libft/libft.a`.

### Usage

Create a separate test program, for example `main.c`:

```c
#include "ft_printf.h"

int main(void)
{
    int n = 42;

    ft_printf("Hello, %s!\n", "42");
    ft_printf("Decimal: %d | Hex: %x\n", n, n);
    ft_printf("Address: %p\n", (void *)&n);
    return (0);
}
```

After the library builds successfully, compile and run the test program:

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o demo
./demo
```

## Algorithm and data structure choices

### 1. Sequential format-string parsing

`ft_printf` scans the null-terminated format string from left to right using an integer index. Ordinary characters are written directly to file descriptor `1` with `write`. When the scanner encounters `%` followed by another character, it advances to that character and delegates processing to a conversion dispatcher. This single-pass approach avoids allocating a separate output buffer and keeps the parsing logic simple.

### 2. Variadic argument handling and dispatch

The implementation uses a `va_list` to track the unnamed arguments supplied after the format string. `va_start` initializes it, `va_arg` retrieves an argument of the type required by each conversion, and `va_end` finishes processing. A small dispatcher (`type_help`) selects a dedicated printing function for `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, or `%%`.

This design separates **parsing** from **representation**: the main loop determines *when* to print a value, while helper functions determine *how* to print it. It also makes individual conversions easier to inspect and test.

### 3. Number conversion

Signed decimal output delegates to the existing Libft function `ft_putnbr_fd`; a separate digit-counting helper calculates the return value, including a minus sign for negative numbers. Unsigned decimal and hexadecimal output use repeated division and remainder operations. Recursive calls print higher-order digits first, and a base string (`0123456789abcdef` or `0123456789ABCDEF`) maps hexadecimal remainders to characters.

Division and remainder are used because they extract digits directly in the desired base without requiring dynamically allocated strings. The recursive approach keeps the digit-ordering logic compact.

### 4. Pointer representation

The pointer helper converts the pointer value to an unsigned integer type and prints a `0x` prefix followed by lowercase hexadecimal digits. In the uploaded implementation, a null pointer prints `(nil)`. The helper recursively writes hexadecimal digits, similarly to the numeric conversion helpers.

### 5. Character counting and output

Each printing helper returns a character count, and `ft_printf` accumulates these counts to produce its return value. For strings, the implementation uses `ft_strlen`; for signed decimal and hexadecimal numbers, it counts digits; and for pointers, it counts emitted bytes. Output is written directly to standard output, rather than collected in a dynamically allocated buffer.

### 6. Data structures and modularity

No linked list, tree, or other collection is needed: the input is a null-terminated C string, arguments are traversed through `va_list`, and the implementation uses local scalar variables, base strings, and the call stack for recursive digit printing. These choices suit a streaming formatter that processes one conversion at a time. Reusing `ft_putchar_fd`, `ft_putstr_fd`, `ft_putnbr_fd`, and `ft_strlen` from Libft reduces duplicated code.

**Limitations:** The supplied implementation does not handle optional formatting flags, widths, or precision. Its error handling and full behavioral equivalence to libc `printf` have not been verified by testing.


## Resources

- Man pages: `man 3 printf`, `man va_start` etc.
- Various internet sites and articles on variadic functions (https://code-vault.net/lesson/cc1b9349b69947ffe53059a914001612) and number base conversion
- Testing software provided by Make (https://github.com/wxsonz/bro42), as well as https://github.com/Tripouille/printfTester, and https://github.com/Tripouille/printfTester
- https://man7.org/linux/man-pages/man3/printf.3.html

### Use of AI

AI was used to explain variadic arguments (`va_list`, `va_start`, `va_arg`, `va_end`), clarify general confusions, to review for bugs, and to help write this README. 
