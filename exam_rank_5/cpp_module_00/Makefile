NAME = ./a.out
CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Warlock.cpp
OBJS = $(SRCS:.cpp=.o)

HEADER = Warlock.hpp

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o:%.c $(HEADER)
	c++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all, fclean, clean, re