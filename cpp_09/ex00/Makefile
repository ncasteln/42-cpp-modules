# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 14:46:08 by ncasteln          #+#    #+#              #
#    Updated: 2024/04/09 10:26:43 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	btc

# @-Wconversion - prevent implicit cast when accuracy is lost.
# @-Wsign-conversion - prevent implicit change of sign.
# @-Wshadow - warns about variable declarations that shadow a variable declared in an outer scope.
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Wshadow -Wconversion -Wsign-conversion -Werror

SRC			=	main.cpp \
				BitcoinExchange.cpp \
				utils.cpp
HEADERS		=	BitcoinExchange.hpp \
				utils.hpp
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
