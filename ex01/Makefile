NAME	:= amazing_blazing_1982_8_addresses_phonebook__ooooo_yeah

SRCS	:=	Contact.cpp \
			PhoneBook.cpp \
			amazing_blazing_1982_8_addresses_phonebook__ooooo_yeah.cpp

OBJS 	:= $(SRCS:.cpp=.o)

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
