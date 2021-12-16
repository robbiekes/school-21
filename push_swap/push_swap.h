// circular doubly-linked list

typedef struct s_stack
{
	long int		data;
	struct s_stack *next;
	struct s_stack *prev;
}					t_stack;

// typedef for stacks a + b

