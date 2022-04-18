#include "thread.h"

// gcc -fsanitize=thread

void *ft_run(void *data)
{
	struct t_data *_data = data;
	pthread_mutex_lock(_data->p_mutex);
	while (*(_data->num) < 10) // try to remove a ptr and parethesis
	{
		(*_data->num)++;
		pthread_mutex_unlock(_data->p_mutex);
		pthread_mutex_lock(_data->p_mutex);
	}
	pthread_mutex_unlock(_data->p_mutex);
	return (0);
}

int main()
{
	int tmp = 0;
	pthread_t id;
	t_mutex mutex;
	struct t_data data;
	data.p_mutex = &mutex;
	data.num = &tmp;
	pthread_mutex_init(&mutex, 0); // проинициализируем мьютекс по умолчанию
	pthread_create(&id, 0, ft_run, &data); // инициализация потока
	pthread_mutex_lock(&mutex);
	while (tmp < 10)
	{
		printf("num = %d\n", tmp);
		pthread_mutex_unlock(&mutex);
		pthread_mutex_lock(&mutex);
	}
	pthread_mutex_unlock(&mutex);
	pthread_join(id, 0);
	pthread_mutex_destroy(&mutex);
	return (0);
}