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

u32	access_last_compile(t_coder *coder, u8 mode)
{
	u32	ret;

	pthread_mutex_lock(&coder->m_compile);
	if (mode == SET)
		coder->last_compile = timestamp();
	ret = coder->last_compile;
	pthread_mutex_unlock(&coder->m_compile);
	return (ret);
}

u16 access_compile_count(t_coder *coder, u8 mode)
{
	u16	ret;

	pthread_mutex_lock(&coder->m_compile);
	if (mode == SET)
		coder->compile_count++;
	ret = coder->compile_count;
	pthread_mutex_unlock(&coder->m_compile);
	return (ret);
}
