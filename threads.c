/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:25:35 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/01 15:59:52 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

// int	ft_if_philo_dead(t_ph_var *var)
// {
// 	if (var->starttime - var->endtime > var->philo->param[TIME_2_DIE])
// 	{
// 		return (0);
// 	}
// 	return (1);
// }

void	ft_philo_b(t_ph_var *var)
{
	pthread_mutex_lock(&(var->philo
			->fork[(var->index + 1) % var->philo->param[PHILO_FORKS]]));
	pthread_mutex_lock((var->philo->print_lock));
	ft_print_states(var, FORK);
	var->last_meal = ft_current_time();
	pthread_mutex_unlock((var->philo->print_lock));
	pthread_mutex_lock((var->philo->print_lock));
	ft_print_states(var, EAT);
	pthread_mutex_unlock((var->philo->print_lock));
	ft_good_sleep(var->philo->param[TIME_2_EAT]);
	(var->philo->eat_limit[var->index])--;
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
}

// void	*ft_check_last_meal(void *ptr)
// {
// 	t_ph_var	*var;
// 	long		tm;

// 	var = (t_ph_var *)ptr;
// 	tm = ft_convert_sec(var->philo->last_meal.tv_sec
// 			- var->philo->start_time, var->philo->last_meal.tv_usec);
// 	// printf("%ld\n", tm);
// 	while (1)
// 	{
// 		if (tm - var->starttime > var->philo->param[TIME_2_DIE])
// 			exit (0);
// 		return (NULL);
// 	}
// }

void	*ft_philo_a(void *ptr)
{
	t_ph_var	*var;

	var = (t_ph_var *)ptr;
	while (1)
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
	var = (t_ph_var *)
		malloc(sizeof(t_ph_var) * philo->param[PHILO_FORKS]);
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->param[PHILO_FORKS]);
	philo->print_lock = malloc(sizeof(pthread_mutex_t));
	philo->time_lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((philo->print_lock), NULL);
	pthread_mutex_init((philo->time_lock), NULL);
	var->test = 0;
	i = 0;
	while (i < philo->param[PHILO_FORKS])
		pthread_mutex_init(&(philo->fork[i++]), NULL);
	i = 0;
	ft_nbr_eat(philo);
	while (i < philo->param[PHILO_FORKS])
	{
		var[i].last_meal = ft_current_time();
		var[i].index = i;
		var[i].philo = philo;
		if (pthread_create(&philo->ph[i], NULL, &ft_philo_a, var + i) != 0)
			printf("ERROR\n");
		i++;
	}

	ft_check_eating2(var, philo);
	// i = 0;
	// while (i < philo->param[PHILO_FORKS])
	// {
	// 	if (pthread_create(&philo->time, NULL, &ft_check_last_meal, var + i) != 0)
	// 		printf("ERROR\n");
	// 	i++;
	// }
	// i = 0;
	// while (i < philo->param[PHILO_FORKS])
	// {
	// 	if (pthread_join(philo->ph[i++], NULL) != 0)
	// 		ft_printf("ERROR\n");
	// }
	// i = 0;
	// while (i < philo->param[PHILO_FORKS])
	// 	pthread_mutex_destroy(&philo->fork[i++]);
}
