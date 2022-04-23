CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
# CFLAGS		= -fsanitize=thread

NAME		= philo

SRCDIR		= ./srcs/
OBJDIR		= ./obj/
INCDIR		= ./includes/

SRCS			= main.c \
				philo.c	\
				destroy_mutexes.c \
				init.c \
				time.c \
				utils.c
				
OBJS			= $(addprefix $(OBJDIR), $(SRCS:.c=.o))

all: $(NAME)

$(OBJDIR)%.o : $(SRCDIR)%.c $(INCDIR)philo.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR) -Ofast

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#test: $(NAME)
#	./$(NAME) 5 800 200 200 2

#test_die: $(NAME)
#	./$(NAME) 4 310 200 100

.PHONY: all clean fclean re bonus