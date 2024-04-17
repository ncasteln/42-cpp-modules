NAME = ./a.out
CXXFLAGS = -Wall -Wextra #-Werror
SRCS = main.cpp Warlock.cpp ASpell.cpp ATarget.cpp Dummy.cpp Fwoosh.cpp

HEADER = Warlock.hpp ASpell.hpp ATarget.hpp Dummy.hpp Fwoosh.hpp
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

re: fclean all

.PHONY: all, fclean, clean, re