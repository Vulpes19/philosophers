/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:01:48 by abaioumy          #+#    #+#             */
/*   Updated: 2022/05/28 18:34:58 by abaioumy         ###   ########.fr       */
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
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

typedef	struct s_ph_var
{
	int				index;
	int				time;
}	t_ph_var;

typedef struct s_philo
{
	pthread_mutex_t	*fork;
	int				*param;
	pthread_t		*ph;
	pthread_mutex_t	print_lock;
}	t_philo;

int		ft_atoi(const char *str);
void	ft_parse_param(char **av, int ac, t_philo *philo);
void	ft_create_threads(t_philo *philo);

#endif