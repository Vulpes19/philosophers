/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:01:48 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/01 15:55:44 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define PHILO_FORKS 0
# define TIME_2_DIE 1
# define TIME_2_EAT 2
# define TIME_2_SLEEP 3
# define NBR_FOR_PHILO_2_EAT 4
# define FORK 5
# define EAT 6
# define SLEEP 7
# define THINK 8

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_states
{
	long	time1;
	int		time2;
	int		time3;
}	t_states;

typedef struct s_time
{
	time_t	t_sec;
}	t_time;

typedef struct s_philo
{
	int				g_ac;
	long			start_time;
	pthread_mutex_t	*fork;
	int				*param;
	pthread_t		*ph;
	pthread_t		time;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*time_lock;
	int				nbr_eat;
	int				*eat_limit;
}	t_philo;

typedef	struct	s_ph_var
{
	int				test;
	int				ifnotdead;
	int				index;
	t_philo			*philo;
	long			last_meal;
}	t_ph_var;

int				ft_atoi(const char *str);
void			ft_parse_param(char **av, int ac, t_philo *philo);
void			ft_create_threads(t_philo *philo, t_ph_var *var);
long			ft_convert_sec(long nbr, long nbr2);
long			ft_current_time(void);
void			ft_good_sleep(long time_s);
void			ft_print_states(t_ph_var *var, int state);
void			ft_free_everything(t_ph_var *var);
void			ft_check_eating(t_ph_var *var);
void			ft_check_eating2(t_ph_var *var, t_philo *philo);
void			ft_nbr_eat(t_philo *philo);

#endif