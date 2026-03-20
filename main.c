# include "codexion.h"

int main(int ac, char **av)
{
	if (!check_args(ac, av))
	{
		write(2, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
