/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:54:40 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/04 00:11:28 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_launch_threads(t_ph_var *var, t_philo *philo)
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
			printf("ERROR\n");
		i++;
	}
	i = 0;
	while (i < philo->param[PHILO_FORKS])
		pthread_detach(var->ph[i++]);
	ft_if_philo_died(var, philo);
}

int	take_cond(t_ph_var *var)
{
	int	cond;

	pthread_mutex_lock((var->philo->end_lock));
	cond = (*var->should_end == 0);
	pthread_mutex_unlock((var->philo->end_lock));
	return (cond);
}

int	ft_check_eating(t_ph_var *var)
{
	int		i;

	i = 0;
	while (i < var->philo->param[PHILO_FORKS])
	{
		pthread_mutex_lock(var->philo->eat_lock);
		if (var[i].eat_limit != 0)
		{
			pthread_mutex_unlock(var->philo->eat_lock);
			return (0);
		}
		pthread_mutex_unlock(var->philo->eat_lock);
		i++;
	}
	pthread_mutex_lock(var->philo->end_lock);
	*var->should_end = 1;
	pthread_mutex_unlock(var->philo->end_lock);
	return (1);
}

void	ft_free_everything(t_ph_var *var)
{
	free(var->philo->param);
	free(var->philo->fork);
	free(var->ph);
	free(var->philo->print_lock);
	free(var->philo->time_lock);
	free(var->philo->end_lock);
}
