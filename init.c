# include "codexion.h"

static bool	init_coders(t_hub *hub)
{
	int	i;
	
	i = -1;
	hub->coders =	malloc(sizeof(t_coder)	* hub->n_coders);
	hub->dongles =	malloc(sizeof(t_dongle)	* hub->n_coders);
	if (!hub->dongles || !hub->coders)
		return (false);
	while (++i < hub->n_coders)
	{
		hub->coders[i].id = i;
		hub->coders[i].hub = hub;
		if (pthread_mutex_init(&hub->dongles[i].mutex, NULL))
			return (false);
		hub->dongles[i].coders[0] =		&hub->coders[i];
		hub->dongles[i].coders[1] =		&hub->coders[hub->n_coders];
		if (i != 0)
			hub->dongles[i].coders[1] =	&hub->coders[i - 1];
		hub->coders[i].dongle[0] =		&hub->dongles[i];
		hub->coders[i].dongle[1] =		&hub->dongles[i + 1];
		if (i == (hub->n_coders - 1))
		{
			hub->coders[i].dongle[0] = &hub->dongles[0];
			hub->coders[i].dongle[1] = &hub->dongles[i];
		}
	}
	return (true);
}

bool	init(t_hub *hub, char **av)
{
	hub->n_coders =				atoi(AV_NB_CODERS);
	hub->burnout_time =			atoi(AV_TBURNOUT);
	hub->compile_time =			atoi(AV_TCOMPILE);
	hub->debug_time =			atoi(AV_TDEBUG);
	hub->refactor_time =		atoi(AV_TREFACT);
	hub->n_compiles =			atoi(AV_NCOMPILE);
	hub->dongle_cd =			atoi(AV_CDDONGLE);

	if (hub->n_coders <= 0)
		return (false);
	printf("[amount][%d]\n[burnout time][%d]\n[compile time][%d]\n[debug time][%d]\n[refactor time][%d]\n[compile amount][%d]\n[dongle cooldown][%d]\n", hub->n_coders, hub->burnout_time, hub->compile_time, hub->debug_time, hub->refactor_time, hub->n_compiles, hub->dongle_cd);
	return (init_coders(hub));
}
