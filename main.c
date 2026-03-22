# include "codexion.h"

//queue system : dongles have 2 pointers(left and right coder)
//they also have an array of 2 integers associated with a stack size, the value of integers can be either RIGHT, LEFT or EMPTY, but they cannot have the same value (except for empty)

static void	*test(void *data)
{
	int		caca;
	t_coder	*coder = (t_coder *) data;
	
	caca = 1;
	caca++;
	caca++;
	caca++;
	printf("[time]%d\n", timestamp() - coder->hub->start);
	pthread_mutex_lock(&coder->dongle[RIGHT]->mutex);
	print_status(coder->id, coder->hub->start, DONGLE);
	pthread_mutex_lock(&coder->dongle[LEFT]->mutex);
	print_status(coder->id, coder->hub->start, DONGLE);
	printf("ok\n");
	pthread_mutex_unlock(&coder->dongle[RIGHT]->mutex);
	pthread_mutex_unlock(&coder->dongle[LEFT]->mutex);

	return (coder);
}

static void start(t_hub *hub)
{
	hub->start = timestamp();
	for (int i = 0; i < hub->n_coders; i++)
		pthread_create(&hub->coders[i].thread, NULL, &test, &hub->coders[i]);
	for (int i = 0; i < hub->n_coders; i++)
		pthread_join(hub->coders[i].thread, NULL);
}

int main(int ac, char **av)
{
	t_hub	hub;

	ft_bzero(&hub, sizeof(t_hub));
	if (!check_args(ac, av) || !init(&hub, av))
	{
		write(2, "Error\n", 6);
		return (free_hub(&hub), EXIT_FAILURE);
	}
	start(&hub);
	free_hub(&hub);
	return (EXIT_SUCCESS);
}
