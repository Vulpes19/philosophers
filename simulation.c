/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:30:50 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/17 10:22:01 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_philo_b(t_ph_var *var)
{
	pthread_mutex_lock(&(var->philo
			->fork[(var->index + 1) % var->philo->param[PHILO_FORKS]]));
	pthread_mutex_lock((var->philo->print_lock));
	ft_print_states(var, FORK);
	pthread_mutex_lock((var->philo->time_lock));
	var->last_meal = ft_current_time();
	pthread_mutex_unlock((var->philo->time_lock));
	pthread_mutex_unlock((var->philo->print_lock));
	pthread_mutex_lock((var->philo->print_lock));
	ft_print_states(var, EAT);
	pthread_mutex_unlock((var->philo->print_lock));
	ft_good_sleep(var->philo->param[TIME_2_EAT]);
	pthread_mutex_lock(var->philo->eat_lock);
	var->eat_limit--;
	pthread_mutex_unlock(var->philo->eat_lock);
	pthread_mutex_unlock(&(var->philo
			->fork[(var->index + 1) % var->philo->param[PHILO_FORKS]]));
	pthread_mutex_unlock(&(var->philo->fork[var->index]));
	pthread_mutex_lock((var->philo->print_lock));
	ft_print_states(var, SLEEP);
	pthread_mutex_unlock((var->philo->print_lock));
	ft_good_sleep(var->philo->param[TIME_2_SLEEP]);
	pthread_mutex_lock((var->philo->print_lock));
	ft_print_states(var, THINK);
	pthread_mutex_unlock((var->philo->print_lock));
}

void	*ft_philo_a(void *ptr)
{
	t_ph_var	*var;

	var = (t_ph_var *)ptr;
	while (take_cond(var))
	{
		if (var->index % 2 != 0)
			usleep(300);
		pthread_mutex_lock(&(var->philo->fork[var->index]));
		pthread_mutex_lock((var->philo->print_lock));
		ft_print_states(var, FORK);
		pthread_mutex_unlock((var->philo->print_lock));
		ft_philo_b(var);
	}
	return (NULL);
}

int	ft_create_threads(t_philo *philo, t_ph_var *var)
{
	int				i;

	i = 0;
	var->ph = (pthread_t *)
		malloc(sizeof(pthread_t) * philo->param[PHILO_FORKS]);
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->param[PHILO_FORKS]);
	philo->print_lock = malloc(sizeof(pthread_mutex_t));
	philo->eat_lock = malloc(sizeof(pthread_mutex_t));
	philo->time_lock = malloc(sizeof(pthread_mutex_t));
	philo->end_lock = malloc(sizeof(pthread_mutex_t));
	if (!var->ph || !philo->fork || !philo->print_lock
		|| !philo->eat_lock || !philo->time_lock || !philo->end_lock)
	{
		ft_handle_errors(1, MEM_FAIL);
		return (0);
	}
	ft_mutex_init(philo);
	if (!ft_launch_threads(var, philo))
		return (0);
	return (1);
}
