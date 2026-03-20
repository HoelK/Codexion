bool ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
           c == '\r' || c == '\f' || c == '\v');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
	{
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
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
