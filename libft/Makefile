# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 00:20:59 by rdu-toi           #+#    #+#              #
#    Updated: 2018/05/22 08:54:01 by rdu-toi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AC = ar -rc

RLIB = ranlib

SRCS = ft_isascii.c	ft_strchr.c	ft_strncmp.c ft_isdigit.c ft_strcmp.c \
ft_strncpy.c ft_atoi.c ft_isprint.c ft_strcpy.c ft_strstr.c ft_isalnum.c \
ft_strdup.c ft_tolower.c ft_isalpha.c ft_strlen.c ft_toupper.c ft_strcat.c \
ft_strncat.c ft_strnstr.c ft_strrchr.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_memalloc.c \
ft_strjoin.c ft_strsub.c ft_strnequ.c ft_strequ.c ft_strclr.c ft_strdel.c \
ft_strnew.c ft_memdel.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_strndup.c ft_isspace.c ft_isupper.c ft_iswspace.c \
ft_strtrim.c ft_strrev.c ft_nbrlen.c ft_itoa.c ft_memcmp.c ft_putnbr_fd.c \
ft_strlenc.c ft_strsplit.c ft_strlcat.c ft_islower.c ft_strlinesplit.c \
ft_linecount.c ft_is_char.c ft_char_index.c ft_strdup_index.c \
get_next_line.c

OBJS = $(SRCS:.c=.o)

$(NAME):
		@$(CC) $(CFLAGS) -c $(SRCS)
		@$(AC) $(NAME) $(OBJS)
		@$(RLIB) $(NAME)
		@echo "[INFO] Library [$(NAME)] successfully created"

all: $(NAME)

clean:
		@rm -rf $(OBJS)
		@echo "[INFO] Object files successfully removed"

fclean:	clean
		@rm -rf $(NAME)
		@echo "[INFO] Library [$(NAME)] successfully removed"

re:		fclean all
		@echo "[INFO] Library [$(NAME)] successfully recreated"
