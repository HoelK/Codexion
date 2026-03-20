# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# define AC_REQUIRED 9

int		ft_isdigit(int c);
bool	ft_isspace(char c);
long	ft_atol(const char *str);
bool	check_args(int ac, char **av);
int		ft_strcmp(const char *s1, const char *s2);
