SRCS		=	$(wildcard *.cpp)	\

OBJS		=	$(SRCS:.cpp=.o)

HEAD		=	./

NAME		=	array

GCC			=	c++

FLAGS		=	-Wall -Werror -Wextra -std=c++98

RM			=	rm -f

%.o:	%.cpp $(wildcard $(HEAD)/*.hpp)
		$(GCC) $(FLAGS) -c $< -o $@ 

$(NAME):	$(HEADS) $(OBJS)
			$(GCC) $(FLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean lib bonus
