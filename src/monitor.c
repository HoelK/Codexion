# include "codexion.h"

static bool	end(t_coder *coder, t_hub *hub)
{
	bool		ret;
	static int	finished_count;

	ret = false;
	if (coder->compile_count == hub->config.n_compiles && !coder->finished)
	{
		coder->finished = true;
		finished_count++;
	}
	if ((timestamp() - coder->last_compile > hub->config.burnout_time) && coder->last_compile != 0)
	{
		print_status(coder->id, hub->start, BURN_OUT);
		ret = access_end(hub, SET);
	}
	if (finished_count == hub->config.n_coders)
		ret = access_end(hub, SET);
	return (ret);
}

void	*monitor(void *data)
{
	int		i;
	t_hub	*hub;

	i = 1;
	hub = (t_hub *)data;
	while (!end(&hub->coders[0], hub))
	{
		while (++i < hub->config.n_coders)
		{
			if (end(&hub->coders[i], hub))
				return (data);
		}
		i = 0;
	}
	return (data);
}
