# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 08:52:54 by ncasteln          #+#    #+#              #
#    Updated: 2024/01/25 08:17:03 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out
CFLAGS		=	-Wall -Wextra -std=c++98 #-Werror
SRC			=	main.cpp
OBJS		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME) -I./

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@ -I./

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
