/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:27:55 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/04 00:15:52 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

static int	ft_if_philo_ate(t_ph_var *var)
{
	if (var->philo->g_ac > 5)
	{
		if (ft_check_eating(var))
		{
			pthread_mutex_lock((var->philo->print_lock));
			printf("%ld ms all philosophers have eaten\n",
				ft_current_time() - var->philo->start_time);
			return (0);
		}
	}
	return (1);
}

void	ft_if_philo_died(t_ph_var *var, t_philo *philo)
{
	long	tm;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (1)
	{
		i = 0;
		while (i < philo->param[PHILO_FORKS])
		{
			tm = ft_current_time();
			if (!ft_if_philo_ate(var))
				return ;
			pthread_mutex_lock((var[i].philo->time_lock));
			if (ft_current_time() - var[i].last_meal > philo->param[TIME_2_DIE])
			{
				pthread_mutex_lock((var->philo->print_lock));
				printf("%ld ms philosopher %d died\n",
					ft_current_time() - var->philo->start_time, i + 1);
				pthread_mutex_lock((var->philo->end_lock));
				*var->should_end = 1;
				pthread_mutex_unlock((var->philo->end_lock));
				return ;
			}
			pthread_mutex_unlock((var[i].philo->time_lock));
			i++;
		}
	}
	return ;
}

long	ft_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_good_sleep(long time_s)
{
	struct timeval	time_n;
	long			time_ms;

	gettimeofday(&time_n, NULL);
	time_ms = (time_n.tv_sec * 1000) + (time_n.tv_usec / 1000);
	usleep(time_s * 1000 * 0.90);
	while (ft_current_time() < time_ms + time_s)
		continue ;
}
