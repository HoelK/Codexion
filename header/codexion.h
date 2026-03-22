# pragma once
# include <stdio.h>
# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# define AC_REQUIRED		9
# define AV_NB_CODERS		av[1]
# define AV_TBURNOUT		av[2]
# define AV_TCOMPILE		av[3]
# define AV_TDEBUG			av[4]
# define AV_TREFACT			av[5]
# define AV_NCOMPILE		av[6]
# define AV_CDDONGLE		av[7]
# define RIGHT				0
# define LEFT				1
# define DONGLE_MESSAGE		"has taken a dongle\n"
# define COMPILE_MESSAGE	"is compiling\n"
# define DEBUG_MESSAGE		"is debugging\n"
# define REFACTOR_MESSAGE	"is refactoring\n"
# define BURNOUT_MESSAGE	"burned out\n"

enum e_status
{
	DONGLE,
	COMPILE,
	DEBUG,
	REFACTOR,
	BURN_OUT
};

typedef struct s_hub t_hub;
typedef struct s_coder t_coder;

typedef struct s_dongle
{
	int				queue[2];
	int				q_size;
	t_coder			*coders[2];
	uint32_t		last_use;
	pthread_mutex_t	mutex;
}	t_dongle;

typedef struct s_coder
{
	int			id;
	bool		burnout;
	pthread_t	thread;
	t_dongle	*dongle[2];
	t_hub		*hub;
}	t_coder;

typedef struct s_hub
{
	uint32_t	start;
	int			n_coders;
	int			n_compiles;
	int			burnout_time;
	int			compile_time;
	int			debug_time;
	int			refactor_time;
	int			dongle_cd;
	t_coder		*coders;
	t_dongle	*dongles;
}	t_hub;

int			ft_isdigit(const char c);
bool		ft_isspace(const char c);
long		ft_atol(const char *str);
void		*ft_bzero(void *s, size_t n);

void		print_status(int id, uint32_t start, uint8_t status);

uint32_t	timestamp(void);
void		ft_sleep(uint32_t u_time);

void		free_hub(t_hub *hub);

void		*routine(void *data);
bool		init(t_hub *hub, char **av);
bool		check_args(int ac, char **av);
