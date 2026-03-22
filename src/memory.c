# include "codexion.h"

void free_hub(t_hub *hub)
{
	int	i;

	i = -1;
	if (!hub)
		return ;
	pthread_mutex_destroy(&hub->m_end);
	if (hub->coders)
		free(hub->coders);
	if (hub->dongles)
	{
		while (++i < hub->config.n_coders)
			pthread_mutex_destroy(&hub->dongles[i].mutex);
		free(hub->dongles);
	}
}
