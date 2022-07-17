/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_and_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:30:59 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/17 10:22:07 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	ft_launch_threads(t_ph_var *var, t_philo *philo)
{
	int	i;
	int	*should_end;

	i = 0;
	should_end = (int *)malloc(4);
	*should_end = 0;
	while (i < philo->param[PHILO_FORKS])
	{
		var[i].eat_limit = philo->param[NBR_FOR_PHILO_2_EAT];
		var[i].last_meal = ft_current_time();
		var[i].index = i;
		var[i].philo = philo;
		var[i].should_end = should_end;
		if (pthread_create(&var->ph[i], NULL, &ft_philo_a, &var[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < philo->param[PHILO_FORKS])
		pthread_detach(var->ph[i++]);
	ft_if_philo_died(var, philo);
	return (1);
}

int	take_cond(t_ph_var *var)
{
	int	cond;

	pthread_mutex_lock((var->philo->end_lock));
	cond = (*var->should_end == 0);
	pthread_mutex_unlock((var->philo->end_lock));
	return (cond);
}
