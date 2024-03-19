NAME	:= Unnecessary_violence

SRCS	:=	main.cpp \
			Weapon.cpp \
			HumanA.cpp
			# HumanB.cpp

OBJS_DIR := obj/
OBJS 	:= $(SRCS:.cpp=.o)
OBJS	:= $(addprefix $(OBJS_DIR),$(OBJS))

CXX	:= g++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS_DIR)%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Object files and directory deleted"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted."

re:	fclean all

.PHONY: all clean fclean re
