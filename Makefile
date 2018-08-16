# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 19:02:24 by rdu-toi           #+#    #+#              #
#    Updated: 2018/08/16 19:02:25 by rdu-toi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

FILLER = srcs/me.filler

FILLER_SRCS = srcs/filler.c srcs/token_params.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AC = ar -rc

RLIB = ranlib

LIBlibft/FT_SRCS = libft/ft_isascii.c libft/ft_strchr.c libft/ft_strncmp.c \
libft/ft_isdigit.c libft/ft_strcmp.c libft/ft_strncpy.c libft/ft_atoi.c \
libft/ft_isprint.c libft/ft_strcpy.c libft/ft_strstr.c libft/ft_isalnum.c \
libft/ft_strdup.c libft/ft_tolower.c libft/ft_isalpha.c libft/ft_strlen.c \
libft/ft_toupper.c libft/ft_strcat.c libft/ft_strncat.c libft/ft_strnstr.c \
libft/ft_strrchr.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c \
libft/ft_putchar.c libft/ft_putstr.c libft/ft_putendl.c libft/ft_putnbr.c \
libft/ft_memalloc.c libft/ft_strjoin.c libft/ft_strsub.c libft/ft_strnequ.c \
libft/ft_strequ.c libft/ft_strclr.c libft/ft_strdel.c libft/ft_strnew.c \
libft/ft_memdel.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strmap.c \
libft/ft_strmapi.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c \
libft/ft_memccpy.c libft/ft_memmove.c libft/ft_memchr.c libft/ft_strndup.c \
libft/ft_isspace.c libft/ft_isupper.c libft/ft_iswspace.c libft/ft_strtrim.c \
libft/ft_strrev.c libft/ft_nbrlen.c libft/ft_itoa.c libft/ft_memcmp.c \
libft/ft_putnbr_fd.c libft/ft_strlenc.c libft/ft_strsplit.c libft/ft_strlcat.c \
libft/ft_islower.c libft/ft_strlinesplit.c libft/ft_linecount.c libft/ft_is_char.c \
libft/ft_char_index.c libft/ft_strdup_index.c get_next_line.c

OBJS = $(LIBlibft/FT_SRCS:.c=.o)

$(LIBFT):
		@$(CC) $(CFLAGS) -c $(LIBlibft/FT_SRCS)
		@$(AC) $(NAME) $(OBJS)
		@$(RLIB) $(NAME)
		@echo "[INFO] Library [$(NAME)] successfully created"

$(FILLER):
		@$(CC) $(CFLAGS) -o $(FILLER) $(LIBFT) $(FILLER_SRCS)

all:
		$(LIBFT)
		$(FILLER)

clean:
		@rm -rf $(OBJS)
		@echo "[INFO] Object files successfully removed"

fclean:	clean
		@rm -rf $(NAME)
		@echo "[INFO] Library [$(LIBFT)] successfully removed"

re:		fclean all
		@echo "[INFO] Library [$(LIBFT)] successfully recreated"
