# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nico <nico@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 14:46:08 by ncasteln          #+#    #+#              #
#    Updated: 2024/03/12 10:14:02 by nico             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out

CXXFLAGS	=	-std=c++98 -Wall -Wextra -Wshadow -Wconversion #-Werror

SRC			=	main.cpp
HEADERS		=	MutantStack.hpp
OBJS		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	c++ $(CXXFLAGS) $(OBJS) -o $(NAME) -I./

%.o: %.cpp $(HEADERS)
	c++ $(CXXFLAGS) -c $< -o $@ -I./

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
