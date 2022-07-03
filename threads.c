/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:25:35 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/03 16:17:39 by abaioumy         ###   ########.fr       */
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
	var->eat_limit--;
	printf("%d\n", var->philo->g_ac);
	if (var->philo->g_ac > 5)
		ft_check_eating(var);
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
	// pthread_mutex_unlock((var->philo->end_lock));
}

int take_cond(t_ph_var *var)
{
	int cond;

	pthread_mutex_lock((var->philo->end_lock));
	cond = (*var->should_end == 0);
	pthread_mutex_unlock((var->philo->end_lock));
	return (cond);
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

void	ft_create_threads(t_philo *philo, t_ph_var *var)
{
	int				i;

	i = 0;
	philo->ph = (pthread_t *)
		malloc(sizeof(pthread_t) * philo->param[PHILO_FORKS]);
	int	*should_end = malloc(4);
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->param[PHILO_FORKS]);
	philo->print_lock = malloc(sizeof(pthread_mutex_t));
	philo->eat_lock = malloc(sizeof(pthread_mutex_t));
	philo->time_lock = malloc(sizeof(pthread_mutex_t));
	philo->end_lock = malloc(sizeof(pthread_mutex_t));
	ft_mutex_init(philo);
	*should_end = 0;
	while (i < philo->param[PHILO_FORKS])
	{
		var[i].eat_limit = philo->param[PHILO_FORKS];
		var[i].last_meal = ft_current_time();
		var[i].index = i;
		var[i].philo = philo;
		var[i].should_end = should_end;
		if (pthread_create(&philo->ph[i], NULL, &ft_philo_a, &var[i]) != 0)
			printf("ERROR\n");
		i++;
	}
	ft_if_philo_died(var, philo);
}
