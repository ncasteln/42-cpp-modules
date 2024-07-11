NAME		=		a.out

CXXFLAGS	=	-Wall -Wextra #-Werror

SRCS		=	main.cpp \
				Warlock.cpp \
				ASpell.cpp \
				ATarget.cpp

HEADERS		=	$(SRCS:.cpp=.hpp)

OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	c++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
