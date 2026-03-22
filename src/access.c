# include "codexion.h"

bool	access_end(t_hub *hub, u8 mode)
{
	bool	ret;

	pthread_mutex_lock(&hub->m_end);
	if (mode == SET)
		hub->end = true;
	ret = hub->end;
	pthread_mutex_unlock(&hub->m_end);
	return (ret);
}
