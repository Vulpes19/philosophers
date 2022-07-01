/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:27:55 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/01 16:05:49 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_check_eating2(t_ph_var *var, t_philo *philo)
{
	long	tm;
	int		i;

	i = 0;
	while (1)
	{
		i = 0;
		tm = ft_current_time();
		while (i < philo->param[PHILO_FORKS])
		{
			if (ft_current_time() - var[i].last_meal > philo->param[TIME_2_DIE])
			{
				printf("died\n");
				exit (0);
			}
			i++;
		}
		sleep(1);
	}
}

long	ft_convert_sec(long nbr, long nbr2)
{
	return ((nbr * 1000) + (nbr2 / 1000));
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
