# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 08:52:54 by ncasteln          #+#    #+#              #
#    Updated: 2024/01/12 16:16:47 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	42phone
CFLAGS		=	-Wall -Wextra -std=c++98 -Werror
SRC			=	42phone.cpp \
				PhoneBook.cpp \
				Contact.cpp
HEADERS		=	PhoneBook.hpp \
				Contact.hpp
OBJS 	= $(SRC:.cpp=.o)

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
