# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 10:10:32 by ncasteln          #+#    #+#              #
#    Updated: 2024/04/03 10:19:30 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out

# @-Wconversion - prevent implicit cast when accuracy is lost.
# @-Wshadow - warns about variable declarations that shadow a variable declared in an outer scope.
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Wshadow -Wconversion -Werror

SRC			=	main.cpp \
				Serializer.cpp
HEADERS		=	Serializer.hpp \
				Data.hpp
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
