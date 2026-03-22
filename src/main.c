# include "codexion.h"

static void start(t_hub *hub)
{
	hub->start = timestamp();
	for (int i = 0; i < hub->n_coders; i++)
		pthread_create(&hub->coders[i].thread, NULL, &routine, &hub->coders[i]);
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
