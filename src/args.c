# include "codexion.h"

static bool	ft_posint(char *s)
{
	while (ft_isspace(*s))
		s++;
	if (!s || strlen(s) > 10)
		return (false);
	if (*s == '+')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}

static bool is_integer(char *str)
{
	long	res;

	if (strlen(str) > 10 || !ft_posint(str))
		return (false);
	res = ft_atol(str);
	return (res >= 0 || res < INT_MAX); 
}

bool check_args(const int ac, char **av)
{
	int		i;
	char	*shreduler;

	if (ac != AC_REQUIRED)
		return (false);
	i = 0;
	shreduler = av[AC_REQUIRED - 1];
	if (strcmp(shreduler, "fifo") && strcmp(shreduler, "edf"))
			return (false);
	while (++i < (AC_REQUIRED - 1))
	{
		if (!*av[i] || !is_integer(av[i]))
			return (false);
	}
	return (true);
}
