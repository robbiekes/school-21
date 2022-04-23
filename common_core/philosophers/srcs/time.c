#include "philo.h"

unsigned int	get_time_ms(void)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, 0);
	return (cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000);
}
