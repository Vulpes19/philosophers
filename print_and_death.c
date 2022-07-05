/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_death.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:30:34 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/05 19:41:04 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	ft_death(t_ph_var *var, t_philo *philo, int i)
{
	if (ft_current_time() - var[i].last_meal >= philo->param[TIME_2_DIE])
	{
		pthread_mutex_lock((var->philo->print_lock));
		printf("%ld ms philosopher %d died\n",
			ft_current_time() - var->philo->start_time, i + 1);
		pthread_mutex_lock((var->philo->end_lock));
		*var->should_end = 1;
		pthread_mutex_unlock((var->philo->end_lock));
		return (0);
	}
	return (1);
}

void	ft_print_states(t_ph_var *var, int state)
{
	long	st;
	long	curr_time;

	st = var->philo->start_time;
	curr_time = ft_current_time();
	if (state == FORK)
	{
		printf("%ld ms philosopher %d has taken a fork\n",
			curr_time - st, var->index + 1);
	}
	if (state == EAT)
	{
		printf("%ld ms philosopher %d has started eating\n",
			curr_time - st, var->index + 1);
	}
	if (state == SLEEP)
	{
		printf("%ld ms philosopher %d is sleeping\n",
			curr_time - st, var->index + 1);
	}
	if (state == THINK)
	{
		printf("%ld ms philosopher %d is thinking\n",
			curr_time - st, var->index + 1);
	}
}
