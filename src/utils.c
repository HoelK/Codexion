# include "codexion.h"

bool ft_isspace(const char c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
           c == '\r' || c == '\f' || c == '\v');
}

int	ft_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}

long ft_atol(const char *str)
{
	long  result = 0;
    int   sign = 1;

    while (ft_isspace(*str))
        str++;

    if (*str == '-')
	{
        sign = -1;
        str++;
    }
	else if (*str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
	{
        result = result * 10 + (*str - '0');
        str++;
    }
    return (sign * result);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*area;

	i = 0;
	area = s;
	while (i < n)
		area[i++] = 0;
	return (s);
}


uint32_t	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void	ft_sleep(u32 u_time)
{
	u32	start;

	start = timestamp();
	while (timestamp() - start < u_time)
		usleep(10);
}

void	print_status(int id, u32 start, u8 status)
{
	u32 time;

	time = timestamp() - start;
	if (status == DONGLE)
		fprintf(stderr, "[%d][%d]%s", id, time, DONGLE_MESSAGE);
	else if (status == COMPILE)
		fprintf(stderr, "[%d][%d]%s", id, time, COMPILE_MESSAGE);
	else if (status == DEBUG)
		fprintf(stderr, "[%d][%d]%s", id, time, DEBUG_MESSAGE);
	else if (status == REFACTOR)
		fprintf(stderr, "[%d][%d]%s", id, time, REFACTOR_MESSAGE);
	else if (status == BURN_OUT)
		fprintf(stderr, "[%d][%d]%s", id, time, BURNOUT_MESSAGE);
}
