NAME	:= ScavTrap

SRCS	:=	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp

OBJS_DIR := obj/
OBJS 	:= $(SRCS:.cpp=.o)
OBJS	:= $(addprefix $(OBJS_DIR),$(OBJS))

CXX	:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98
DEPFLAGS := -MMD -MP

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJS_DIR)%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Object files and directory deleted"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted."

re:	fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
