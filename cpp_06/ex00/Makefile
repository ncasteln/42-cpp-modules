# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 09:20:05 by ncasteln          #+#    #+#              #
#    Updated: 2024/04/03 16:21:21 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	convert

# @-Wconversion - prevent implicit cast when accuracy is lost.
# @-Wshadow - warns about variable declarations that shadow a variable declared in an outer scope.
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Wshadow -Wconversion -Werror

SRC			=	main.cpp \
				ScalarConverter.cpp \
				get_type.cpp \
				handle_type.cpp \
				display.cpp
HEADERS		=	ScalarConverter.hpp \
				get_type.hpp \
				handle_type.hpp \
				display.hpp
OBJS		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	c++ $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	c++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
