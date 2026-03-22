# include "codexion.h"

static bool init_monitor(t_hub *hub)
{
	ft_bzero(&hub->monitor, sizeof(t_monitor *));
	return (true);
}

static void	init_config(char **av, t_hub *hub)
{
	hub->config.n_coders =		atoi(AV_NB_CODERS);
	hub->config.burnout_time =	atoi(AV_TBURNOUT);
	hub->config.compile_time =	atoi(AV_TCOMPILE);
	hub->config.debug_time =	atoi(AV_TDEBUG);
	hub->config.refactor_time =	atoi(AV_TREFACT);
	hub->config.n_compiles =	atoi(AV_NCOMPILE);
	hub->config.dongle_cd =		atoi(AV_CDDONGLE);
}

static bool init_dongle(int i, t_hub *hub)
{
	hub->dongles[i].coders[0] =	&hub->coders[i];
	hub->dongles[i].coders[1] =	&hub->coders[hub->config.n_coders];
	if (i != 0)
		hub->dongles[i].coders[1] =	&hub->coders[i - 1];
	if (pthread_mutex_init(&hub->dongles[i].mutex, NULL))
		return (false);
	return (true);
}

static void	init_coder(int i, t_hub *hub)
{
	hub->coders[i].id = i;
	hub->coders[i].hub = hub;
	hub->coders[i].last_compile = 0;
	hub->coders[i].compile_count = 0;
	hub->coders[i].dongle[0] =	&hub->dongles[i];
	hub->coders[i].dongle[1] =	&hub->dongles[i + 1];
	if (i == (hub->config.n_coders - 1))
	{
		hub->coders[i].dongle[0] = &hub->dongles[0];
		hub->coders[i].dongle[1] = &hub->dongles[i];
	}
}

bool	init(t_hub *hub, char **av)
{
	int i;

	i = -1;
	init_config(av, hub);
	if (hub->config.n_coders <= 0)
		return (false);
	init_monitor(hub);
	if (pthread_mutex_init(&hub->m_end, NULL))
		return (false);
	hub->coders =	malloc(sizeof(t_coder)	* hub->config.n_coders);
	hub->dongles =	malloc(sizeof(t_dongle)	* hub->config.n_coders);
	if (!hub->dongles || !hub->coders)
		return (false);
	while (++i < hub->config.n_coders)
	{
		if (!init_dongle(i, hub))
			return (false);
		init_coder(i, hub);
	}
	return (true);
	//printf("[amount][%d]\n[burnout time][%d]\n[compile time][%d]\n[debug time][%d]\n[refactor time][%d]\n[compile amount][%d]\n[dongle cooldown][%d]\n", hub->n_coders, hub->burnout_time, hub->compile_time, hub->debug_time, hub->refactor_time, hub->n_compiles, hub->dongle_cd);
}
