NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --no-print-directory
$(VERBOSE).SILENT:

SRCS = ft_printf.c \
       srcs/ft_put_unsigned.c \
       srcs/ft_printf_putchar.c \
       srcs/ft_put_hexadecimal.c \
       srcs/ft_printf_putnbr.c \
       srcs/ft_printf_putstr.c \
       srcs/ft_printf_strlen.c \
       srcs/ft_printf_itoa.c

OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
