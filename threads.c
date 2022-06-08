/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:25:35 by abaioumy          #+#    #+#             */
/*   Updated: 2022/06/08 21:41:25 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_assign_var(t_ph_var *var)
{
	var->ifnotdead = 1;
}

void	*func(void *ptr)
{
	t_ph_var	*var;

	var = (t_ph_var *)ptr;
	while (var->ifnotdead)
	{
		if (var->index % 2 != 0)
			usleep(500);
		gettimeofday(&(var->philo->current_time), NULL);
		pthread_mutex_lock(&(var->philo->fork[var->index]));
		ft_print_states(var, FORK);
		pthread_mutex_lock(&(var->philo
				->fork[(var->index + 1) % var->philo->param[PHILO_FORKS]]));
		ft_print_states(var, FORK);
		ft_print_states(var, EAT);
		ft_good_sleep(var->philo->param[TIME_2_EAT]);
		var->l_time_eat = ft_convert_sec( var->philo->current_time.tv_sec - var->philo->start_time, var->philo->current_time.tv_usec);
		pthread_mutex_unlock(&(var->philo
				->fork[(var->index + 1) % var->philo->param[PHILO_FORKS]]));
		if (var->l_time_eat > var->philo->param[TIME_2_DIE])
			exit(0);
		pthread_mutex_unlock(&(var->philo->fork[var->index]));
		ft_print_states(var, SLEEP);
		ft_good_sleep(var->philo->param[TIME_2_SLEEP]);
		ft_print_states(var, THINK);
	}
	return (NULL);
}

void	ft_create_threads(t_philo *philo)
{
	int				i;
	t_ph_var		*var;

	i = 0;
	philo->ph = (pthread_t *)
		malloc(sizeof(pthread_t) * philo->param[PHILO_FORKS]);
	var = (t_ph_var *)
		malloc(sizeof(t_ph_var) * philo->param[PHILO_FORKS]);
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->param[PHILO_FORKS]);
	philo->print_lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((philo->print_lock), NULL);
	i = 0;
	while (i < philo->param[PHILO_FORKS])
		pthread_mutex_init(&(philo->fork[i++]), NULL);
	i = 0;
	ft_assign_var(var);
	while (i < philo->param[PHILO_FORKS])
	{
		var[i].index = i;
		var[i].philo = philo;
		if (pthread_create(&philo->ph[i], NULL, &func, var + i) != 0)
			ft_printf("ERROR\n");
		i++;
	}
	i = 0;
	while (i < philo->param[PHILO_FORKS])
	{
		if (pthread_join(philo->ph[i++], NULL) != 0)
			ft_printf("ERROR\n");
	}
	i = 0;
	while (i < philo->param[PHILO_FORKS])
		pthread_mutex_destroy(&philo->fork[i++]);
}
