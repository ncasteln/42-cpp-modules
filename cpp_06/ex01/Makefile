# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nico <nico@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 14:46:08 by ncasteln          #+#    #+#              #
#    Updated: 2024/04/02 14:45:44 by nico             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out

# @-Wconversion - prevent implicit cast when accuracy is lost
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
