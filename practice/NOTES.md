- check if `print_hex_lower` and `print_hex_upper` can be combined?
-- maybe adding a an option for int 0 / 1, and then sharing the same function.

```
print_hex(unsigned int nbr, int or)
{
    if (or == 0)
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
}
```

something like that?..