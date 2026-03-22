# include "codexion.h"

//cd dongle et queue a implementer2

void	lock_dongle(int id, uint32_t start, t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->mutex);
	print_status(id, start, DONGLE);
	dongle->last_use = timestamp();
}

static void	compile(t_coder *coder, int time)
{
	lock_dongle(coder->id, coder->hub->start, coder->dongle[RIGHT]);
	lock_dongle(coder->id, coder->hub->start, coder->dongle[LEFT]);
	ft_sleep(time);
	print_status(coder->id, coder->hub->start, COMPILE);
	pthread_mutex_unlock(&coder->dongle[RIGHT]->mutex);
	pthread_mutex_unlock(&coder->dongle[LEFT]->mutex);
}

static void	debug(const t_coder *coder, int time)
{
	ft_sleep(time);
	print_status(coder->id, coder->hub->start, DEBUG);
}

static void	refactor(const t_coder *coder, int time)
{
	ft_sleep(time);
	print_status(coder->id, coder->hub->start, REFACTOR);
}

void *routine(void *data)
{
	t_coder *coder;

	coder = (t_coder *)data;
	while (true)
	{
		compile(coder, coder->hub->compile_time);
		debug(coder, coder->hub->debug_time);
		refactor(coder, coder->hub->refactor_time);
	}
}
