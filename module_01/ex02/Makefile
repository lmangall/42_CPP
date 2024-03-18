NAME	:= a_very_brainy_program

SRCS	:=	main.cpp

OBJS 	:= $(SRCS:main.cpp=main.o)

CXX	:= g++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "Object files deleted"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted."

re:	fclean all

.PHONY: all clean fclean re
