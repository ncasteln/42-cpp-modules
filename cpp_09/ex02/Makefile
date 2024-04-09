# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 14:46:08 by ncasteln          #+#    #+#              #
#    Updated: 2024/04/09 15:32:56 by ncasteln         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PmergeMe

# @-Wconversion - prevent implicit cast when accuracy is lost.
# @-Wsign-conversion - prevent implicit change of sign.
# @-Wshadow - warns about variable declarations that shadow a variable declared in an outer scope.
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Wshadow -Wconversion -Wsign-conversion #-Werror

SRC			=	main.cpp

HEADERS		=	PmergeMe.hpp \
				utils.hpp
OBJS		=	$(SRC:.cpp=.o)

VERBOSE		=	-DVERBOSE=0
ifeq ($(filter verbose,$(MAKECMDGOALS)),verbose)
	VERBOSE	=	-DVERBOSE=1
endif

all: $(NAME)

verbose: fclean $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	c++ $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	c++ $(CXXFLAGS) -c $< -o $@ $(VERBOSE)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, verbose
