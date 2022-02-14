NAME 			= 	pipex
BONUSNAME		= 	pipex_bonus

CC 				= 	gcc
CFLAGS			= 	-Wall -Wextra -Werror
RM 				= 	rm -rf

SRCDIR 			= 	./srcs/
OBJDIR 			= 	./obj/
INCDIR 			= 	./includes/

SRCS 			= 	pipex.c ft_split.c	utils.c
BONUSSRCS		= 	pipex_bonus.c ft_split.c	utils.c get_next_line.c	get_next_line_utils.c

OBJ 			= 	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

BONUSOBJ 		= 	$(addprefix $(OBJDIR), $(BONUSSRCS:.c=.o))

all				: 	$(NAME)

$(OBJDIR)%.o 	: 	$(SRCDIR)%.c $(INCDIR)pipex.h
					$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR) 

$(BONUSDIR)%.o 	: 	$(SRCDIR)%.c $(INCDIR)pipex_bonus.h $(INCDIR)get_next_line.h
					$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR) 

$(NAME)			: 	$(OBJDIR) $(OBJ) $(INCDIR) 
					$(CC) $(OBJ) -o $(NAME)

clean			:
					$(RM) $(OBJDIR)

fclean			: 	clean
					$(RM) $(NAME)
					$(RM) $(BONUSNAME)

re				: 	fclean all

bonus			: 	$(BONUSNAME)

$(BONUSNAME)	: 	$(OBJDIR) $(BONUSOBJ)
					$(CC) $(CFLAGS)  $(BONUSOBJ) -o $(BONUSNAME)

$(OBJDIR)		:
					mkdir -p $(OBJDIR)
$(BONUSDIR)		:
					mkdir -p $(BONUSOBJ)