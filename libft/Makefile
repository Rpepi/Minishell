# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:09:25 by rpepi             #+#    #+#              #
#    Updated: 2024/03/07 17:57:20 by rpepi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIBFT = libft.a

SRCS_LIBFT = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
              ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
              ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
              ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memcpy.c \
              ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
              ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
              ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
              ft_print_char.c ft_print_hexa.c ft_print_ptr.c ft_print_unsigned.c \
              ft_printf_utils.c ft_printf.c ft_print_int.c ft_print_string.c ft_print_percent.c \
              get_next_line_utils.c get_next_line.c ft_strndup.c

OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)

BONUS_LIBFT = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
               ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
               ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS_LIBFT = $(BONUS_LIBFT:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

LIB = ar rcs

all: $(NAME_LIBFT)


$(NAME_LIBFT): $(OBJS_LIBFT) $(BONUS_OBJS_LIBFT) 
	    @$(LIB) $(NAME_LIBFT) $(OBJS_LIBFT) $(BONUS_OBJS_LIBFT) 

clean:
	    @$(RM) $(OBJS_LIBFT) $(BONUS_OBJS_LIBFT) 

fclean: clean
	    @$(RM) $(NAME_LIBFT) 

re: fclean all

bonus: $(OBJS_LIBFT) $(BONUS_OBJS_LIBFT)
	    @$(LIB) $(NAME_LIBFT) $(OBJS_LIBFT) $(BONUS_OBJS_LIBFT)
.PHONY: all clean fclean re bonus