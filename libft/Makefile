# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 15:22:11 by eblancha          #+#    #+#              #
#    Updated: 2025/01/29 08:27:19 by eblancha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iprintf -Iget_next_line

MAKEFLAGS += --no-print-directory
$(VERBOSE).SILENT:

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
       ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
       ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
       ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_strtrim.c ft_split.c \
       ft_itoa.c ft_strmapi.c ft_striteri.c ft_allocate_string.c printf/ft_printf.c printf/srcs/ft_printf_itoa.c \
       printf/srcs/ft_put_unsigned.c printf/srcs/ft_printf_putchar.c printf/srcs/ft_put_hexadecimal.c \
       printf/srcs/ft_printf_putnbr.c printf/srcs/ft_printf_putstr.c printf/srcs/ft_printf_strlen.c \
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	     ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	     ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)

SRCS_ALL = $(SRCS) $(SRCS_BONUS)

OBJS_ALL = $(SRCS_ALL:.c=.o)

#INC = printf get_next_line

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJS_ALL)
	ar rsc $(NAME) $(OBJS_ALL)
	ranlib $(NAME)

clean:
	rm -f $(OBJS_ALL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
