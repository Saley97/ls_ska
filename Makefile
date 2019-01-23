# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/31 20:35:25 by sbednar           #+#    #+#              #
#    Updated: 2019/01/23 14:44:20 by edraugr-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags description:
#
# -l      (The lowercase letter ``ell''.)  List in long format.  (See
#         below.)  If the output is to a terminal, a total sum for all the
#         file sizes is output on a line before the long listing.
#
# -R      Recursively list subdirectories encountered.
#
# -a      Include directory entries whose names begin with a dot (.).
#
# -r      Reverse the order of the sort to get reverse lexicographical
#         order or the oldest entries first (or largest files last, if com-
#         bined with sort by size
#
# -t      Sort by time modified (most recently modified first) before sort-
#         ing the operands by lexicographical order.

NAME		=	ft_ls

LIB_DIR		=	./lib
SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./inc

FT_DIR		=	$(addprefix $(LIB_DIR)/,libft)
FT_INC_DIR	=	$(addprefix $(FT_DIR)/,inc)

FT			=	$(addprefix $(FT_DIR)/,libft.a)

SRC			= 	ft_ls.c \
				utils.c \
				main.c \
				init_finf.c \
				lst_insert_new.c
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC			=	gcc
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-g

all: $(NAME)

$(NAME): $(FT) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I$(INC_DIR) -I$(FT_INC_DIR) -L$(FT_DIR) -lft -o $(NAME)

$(FT):
	$(MAKE) -C $(FT_DIR) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(FT_INC_DIR) -o $@ -c $<

clean:
	$(MAKE) -C $(FT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(FT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
