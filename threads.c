/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:25:35 by abaioumy          #+#    #+#             */
/*   Updated: 2022/05/28 18:36:06 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*func(void *ptr)
{
	t_ph_var	*var;
	t_philo		*philo;

	var = (t_ph_var *)ptr;
	philo = NULL;
	// while(1);
	// ft_printf("%d\n", nbr);
	pthread_mutex_lock(&var->fork);
	ft_printf("philosopher %d has taken a fork\n", var->index + 1);
	pthread_mutex_lock(&var->fork);
	// ft_printf("philosopher %d has started two eating\n",
	// 	var->index % philo->param[PHILO_FORKS]);
	// pthread_mutex_unlock(&philo->fork[var->index + 1]);
	// pthread_mutex_unlock(&philo->fork[var->index % philo->param[PHILO_FORKS]]);
	// ft_printf("philosopher %d is sleeping\n", var->index + 1);
	// ft_printf("philosopher %d is thinking\n", var->index + 1);
	return (NULL);
}

void	ft_create_threads(t_philo *philo)
{
	int			i;
	t_ph_var	*var;

	philo->ph = (pthread_t *)
		malloc(sizeof(pthread_t) * philo->param[PHILO_FORKS]);
	var = (t_ph_var *)
		malloc(sizeof(t_ph_var) * philo->param[PHILO_FORKS]);
	philo->fork = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * philo->param[PHILO_FORKS]);
	i = 0;
	while (i < philo->param[PHILO_FORKS])
		pthread_mutex_init(&philo->fork[i++], NULL);
	i = 0;
	pthread_mutex_init(&philo->print_lock, NULL);
	while (i < philo->param[PHILO_FORKS])
	{
		var[i].index = i;
		var[i].fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(&var[i].fork, NULL);
		if (pthread_create(&philo->ph[i], NULL, &func, &var[i]) != 0)
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
		pthread_mutex_destroy(&var[i++].fork);
	// while (i < philo->param[PHILO_FORKS])
	// 	pthread_mutex_destroy(&philo->fork[i++]);
}
