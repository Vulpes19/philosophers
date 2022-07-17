/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_death.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:31:07 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/14 14:00:15 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_if_philo_died(t_ph_var *var, t_philo *philo)
{
	long	tm;
	int		i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo->param[PHILO_FORKS])
		{
			tm = ft_current_time();
			if (!ft_if_philo_ate(var))
				return ;
			pthread_mutex_lock((var->philo->time_lock));
			if (!ft_death(var, philo, i))
				return ;
			pthread_mutex_unlock((var->philo->time_lock));
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
	usleep(time_s * 1000 * 0.89);
	while (ft_current_time() < time_ms + time_s)
		continue ;
}
