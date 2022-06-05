/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:01:48 by abaioumy          #+#    #+#             */
/*   Updated: 2022/06/05 16:44:15 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define PHILO_FORKS 0
# define TIME_2_DIE 1
# define TIME_2_EAT 2
# define TIME_2_SLEEP 3
# define NBR_FOR_PHILO_2_EAT 4

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_time
{
	time_t	t_sec;
}	t_time;

typedef struct s_philo
{
	int				start_time;
	pthread_mutex_t	*fork;
	int				*param;
	pthread_t		*ph;
	pthread_mutex_t	*print_lock;
	struct timeval	current_time;
}	t_philo;

typedef	struct s_ph_var
{
	int				index;
	t_philo			*philo;
}	t_ph_var;

int		ft_atoi(const char *str);
void	ft_parse_param(char **av, int ac, t_philo *philo);
void	ft_create_threads(t_philo *philo);
long	ft_convert_sec(long nbr, int nbr2);

#endif