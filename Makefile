# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 17:42:24 by ykondrat          #+#    #+#              #
#    Updated: 2017/03/06 14:08:56 by ykondrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol_burningship.c\
	  fractol_create_wi.c\
	  fractol_error.c\
	  fractol_get_color.c\
	  fractol_julia.c\
	  fractol_key_bs.c\
	  fractol_key_jul.c\
	  fractol_key_man.c\
	  fractol_key_sie.c\
	  fractol_main.c\
	  fractol_mandelbrot.c\
	  fractol_mouse_bs.c\
	  fractol_mouse_jul.c\
	  fractol_mouse_man.c\
	  fractol_pixel_put.c\
	  fractol_putstr.c\
	  fractol_sierpinski.c\
	  fractol_zero.c

LIB = -L ./libft/ -lft

SRC_O = $(SRC:.c=.o)

INC = fractol.h

INC_LIB = libft/libft.h

FLAG = -Wall -Werror -Wextra

MLX_FLAG = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
	
$(NAME): $(SRC_O) $(INC_LIB) $(INC)
	@echo "\033[33mCompiling started..."
	@make -C ./libft/
	@echo "\033[33mCompiling project...\033[0m"
	gcc -o $(NAME) $(SRC_O) $(LIB) $(MLX_FLAG)
	@echo "\033[32;01mSuccess!!!"
	@echo "\033[32;05mReady to go =)"

%.o: %.c
	@gcc $(FLAG) -I $(INC) -c $<

clean:
	@echo "\033[31mRemoving objects...\033[0m"
	rm -f $(SRC_O)
	@make clean -C ./libft/

fclean: clean
	@echo "\033[31mRemoving executable\033[0m"
	rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all
