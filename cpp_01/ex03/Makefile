# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 08:52:54 by ncasteln          #+#    #+#              #
#    Updated: 2024/01/17 08:51:44 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out
CFLAGS		=	-Wall -Wextra -std=c++98 -Werror
SRC			=	main.cpp \
				Weapon.cpp \
				HumanA.cpp \
				HumanB.cpp
OBJS		=	$(SRC:.cpp=.o)
HEADERS		=	Weapon.hpp \
				HumanA.hpp \
				HumanB.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME) -I./

%.o: %.cpp $(HEADERS)
	c++ $(CFLAGS) -c $< -o $@ -I./

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
