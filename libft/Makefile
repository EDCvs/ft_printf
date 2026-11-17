NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs

SRCS		= ft_strlen.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re