CC			= c++
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -Ofast -MMD -std=c++98

NAME		= zombie

SRCDIR		= ./
OBJDIR		= ./build
INCDIR		= ./

SRC			= $(SRCDIR)/main.cpp \
			  $(SRCDIR)/Zombie.cpp \
			  $(SRCDIR)/newZombie.cpp \
			  $(SRCDIR)/randomChump.cpp

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
