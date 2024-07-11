NAME		=		a.out

CXXFLAGS	=	-Wall -Wextra #-Werror

SRCS		=	main.cpp \
				Warlock.cpp \
				ASpell.cpp \
				ATarget.cpp \
				Fwoosh.cpp \
				Dummy.cpp \
				Fireball.cpp \
				Polymorph.cpp \
				SpellBook.cpp \
				BrickWall.cpp \
				TargetGenerator.cpp

HEADERS		=	Warlock.hpp \
				TargetGenerator.hpp \
				SpellBook.hpp \
				ASpell.hpp \
				ATarget.hpp \
				Fwoosh.hpp \
				Fireball.hpp \
				BrickWall.hpp \
				Polymorph.hpp \
				Dummy.hpp

OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	c++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
