CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -Ofast -MMD

NAME		= philo

SRCDIR		= ./
OBJDIR		= ./build
INCDIR		= ./

SRC			=	$(SRCDIR)/main.c \
				$(SRCDIR)/init.c \
				$(SRCDIR)/time.c \
				$(SRCDIR)/philo.c \
				$(SRCDIR)/lib_utils.c \
				$(SRCDIR)/philo_utils.c \
				$(SRCDIR)/destroy_mutexes.c

OBJ			= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
DEP			= $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
