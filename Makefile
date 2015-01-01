# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmangili <rmangili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/16 12:16:28 by rmangili          #+#    #+#              #
#    Updated: 2014/12/29 12:31:03 by rmangili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIB = libft/libft.a

SRC = ft_fill_flags.c

OBJ = ft_fill_flags.o

FLAGS = -Wall -Werror -Wextra

$(NAME): all

all:
	@gcc -c -I. $(FLAGS) $(SRC) $(LIB) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Make [OK]!"

relib: 
	@cd libft; make; make clean
	@echo "Make lib done!"

clean:
	@rm -rf $(OBJ)
	@echo "Make clean [OK]!"

fclean: clean
	@rm -rf libft.a
	@echo "Make fclean[OK]!"

re: fclean all
	@echo "Make re [OK]!"
