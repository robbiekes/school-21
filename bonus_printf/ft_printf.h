#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_args
{
	char conversion;
	int width;
	int precision;
} t_args;



#endif