# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 08:52:54 by ncasteln          #+#    #+#              #
#    Updated: 2024/01/23 10:18:26 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	harl
CFLAGS		=	-Wall -Wextra -std=c++98 -Werror
SRC			=	main.cpp \
				Harl.cpp
OBJS		=	$(SRC:.cpp=.o)
HEADERS		=	Harl.hpp

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
