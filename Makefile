NAME     = libftprintf.a
LIBFT_DIR = libft
LIBFT    = $(LIBFT_DIR)/libft.a

CC       = cc
CFLAGS   = -Wall -Wextra -Werror

SRCS     = ft_printf.c print_char.c print_str.c print_pointer.c \
           print_int_dec.c print_unsigned.c print_hex_lower.c \
		   print_hex_upper.c
OBJS     = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
