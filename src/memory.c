# include "codexion.h"

void free_hub(t_hub *hub)
{
	int	i;

	if (!hub)
		return ;
	pthread_mutex_destroy(&hub->m_end);
	if (hub->coders)
	{
		i = -1;
		while (++i < hub->config.n_coders)
			pthread_mutex_destroy(&hub->coders[i].m_compile);
		free(hub->coders);
	}
	if (hub->dongles)
	{
		i = -1;
		while (++i < hub->config.n_coders)
			pthread_mutex_destroy(&hub->dongles[i].mutex);
		free(hub->dongles);
	}
}
