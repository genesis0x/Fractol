# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 11:14:53 by hahadiou          #+#    #+#              #
#    Updated: 2023/02/19 23:29:21 by hahadiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc

FLAGS	= -Wall -Wextra -Werror

NAME	= fractol

INC	= inc

LIBFT_PATH	= libft

SRC_PATH	= src

OBJ_PATH	= obj

SRCS =  init.c \
		event_hooks.c \
		mouse_hooks.c \
		main.c \
		shape.c \
		utils.c \
		check.c
		
SRC		= $(addprefix $(SRC_PATH)/,$(SRCS))
OBJ		= $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

all: $(NAME)


$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling Fractol...$(NOC)"
	@$(CC)  $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $@ $^ 
	@echo "$(GREEN)$@$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)/$(NAME).h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I$(INC) -c -o $@ $<

run :
		make re && ./fractol
clean:
	@echo "$(RED)Deleting Fractol OBJS ✔️ $(NOC)"
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJB_PATH)

fclean: clean
	@echo "$(RED)Deleting Fractol Binary ✔️$(NOC)"
	@rm -f $(NAME) ${NAMEB}

re: fclean all

.PHONY:	all clean fclean re  
