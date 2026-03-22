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

void	ft_sleep(uint32_t u_time)
{
	uint32_t	start;

	start = timestamp();
	while (timestamp() - start < u_time)
		usleep(10);
}

void	ft_write(const char *s)
{
	write(2, s, strlen(s));
}

void	print_status(int id, uint32_t start, uint8_t status)
{
	fprintf(stderr, "[%d][%d]", id, timestamp() - start);
	if (status == DONGLE)
		ft_write(DONGLE_MESSAGE);
	else if (status == COMPILE)
		ft_write(COMPILE_MESSAGE);
	else if (status == DEBUG)
		ft_write(DEBUG_MESSAGE);
	else if (status == REFACTOR)
		ft_write(REFACTOR_MESSAGE);
	else if (status == BURN_OUT)
		ft_write(BURNOUT_MESSAGE);
}
