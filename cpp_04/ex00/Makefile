# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 14:46:08 by ncasteln          #+#    #+#              #
#    Updated: 2024/02/12 16:20:19 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out
CFLAGS		=	-Wall -Wextra -std=c++98 -Wshadow #-Werror

SRC			=	main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp
HEADERS		=	Animal.hpp \
				Dog.hpp \
				Cat.hpp
OBJS		=	$(SRC:.cpp=.o)

BAD_SRC		=	wrong_main.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp
BAD_HEADERS	=	WrongAnimal.hpp \
				WrongCat.cpp
BAD_OBJS	=	$(BAD_SRC:.cpp=.o)

all: $(NAME)

wrong: $(NAME)_bad

$(NAME)_bad: $(BAD_OBJS) $(BAD_HEADERS)
	c++ $(CFLAGS) $(BAD_OBJS) -o $(NAME)_bad -I./

$(NAME): $(OBJS) $(HEADERS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME) -I./

%.o: %.cpp $(HEADERS)
	c++ $(CFLAGS) -c $< -o $@ -I./

clean:
	rm -rf $(OBJS) $(BAD_OBJS)

fclean: clean
	rm -rf $(NAME) $(NAME)_bad

re: fclean all

.PHONY: all, clean, fclean, re
