# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/25 17:38:12 by abouvero          #+#    #+#              #
#    Updated: 2018/06/29 12:56:37 by mfonteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
SRC_PATH = src
SRC_NAME = main.c \
	   error.c \
	   free.c \
	   get_champ.c \
	   init_champs.c \
	   init.c \
	   init_score.c \
	   init_pairy_print_header.c \
	   print_score.c \
	   process.c \
	   option.c \
	   init_tools.c \
	   inti_visu.c \
	   run.c \
	   instr_params.c \
	   instr_tools.c \
	   instr_loaders.c \
	   instr_operators.c \
	   instr_storage.c \
	   instr_forks.c \
	   convert.c \
	   instr_params_check.c \
	   init_visu.c \
	   visu_run.c \
	   op.c
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj
CPPFLAGS = -Iinclude
LIBFT = libft/libft.a
LIBDIR = libft
CC = gcc
CFLAGS = -Werror -Wall -Wextra #-fsanitize=address -g3

INC_PATH = include
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re, norme

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -lncurses $(LIBFT)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBDIR)

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/*.h

clean:
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -fv $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
