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

FILLER_SRCS = srcs/filler.c srcs/token_params.c srcs/placement.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AC = ar -rc

RLIB = ranlib

OBJS = $(FILLER_SRCS:.c=.o)

$(NAME):
		@$(CC) $(CFLAGS) -c $(FILLER_SRCS)
		@$(AC) $(FILLER) $(OBJS)
		@$(RLIB) $(NAME)
		@echo "[INFO] Library [filler] successfully created"

$(FILLER):
		@$(CC) $(CFLAGS) -o $(FILLER) $(LIBFT) $(FILLER_SRCS)

all:	$(FILLER)

recomplibft:
		make re -C libft

cleanlibft:
		make clean -C libft

clean:
		@rm -rf $(OBJS)
		@echo "[INFO] Object files successfully removed"

fclean: clean
		@rm -rf $(FILLER)
		@echo "[INFO] Library [$(FILLER)] successfully removed"

re:		fclean recomplibft cleanlibft all
		@echo "[INFO] Library [libft] successfully recompiled"
		@echo "[INFO] Library [$(LIBFT)] successfully recompiled"
