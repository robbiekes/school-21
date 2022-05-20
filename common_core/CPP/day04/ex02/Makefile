CC			= c++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -Ofast -MMD -std=c++98 -fsanitize=address

NAME		= Brain

SRCDIR		= ./
OBJDIR		= ./build
INCDIR		= ./

SRC			= $(SRCDIR)/main.cpp \
			  $(SRCDIR)/Animal.cpp \
			  $(SRCDIR)/Cat.cpp \
			  $(SRCDIR)/Dog.cpp \
			  $(SRCDIR)/Brain.cpp



OBJ			= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
DEP			= $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
