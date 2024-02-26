# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 14:46:08 by ncasteln          #+#    #+#              #
#    Updated: 2024/02/26 16:04:13 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out
CFLAGS		=	-Wall -Wextra -std=c++98 -Wshadow -Werror

SRC			=	main.cpp \
				AAnimal.cpp \
				Dog.cpp \
				Cat.cpp \
				Brain.cpp
HEADERS		=	AAnimal.hpp \
				Dog.hpp \
				Cat.hpp \
				Brain.hpp
OBJS		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME) -I./

%.o: %.cpp $(HEADERS)
	c++ $(CFLAGS) -c $< -o $@ -I./

clean:
	rm -rf $(OBJS) $(BAD_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
