/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:25:35 by abaioumy          #+#    #+#             */
/*   Updated: 2022/06/05 16:42:03 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	*func(void *ptr)
{
	t_ph_var	*var;
	int			time;

	var = (t_ph_var *)ptr;
	while (1)
	{
		if (var->index % 2 != 0)
			usleep(500);
		time = var->philo->param[TIME_2_EAT];
		gettimeofday(&(var->philo->current_time), NULL);
		pthread_mutex_lock(&(var->philo->fork[var->index]));
		printf("%ld philosopher %d has taken a fork\n",
			ft_convert_sec(var->philo->current_time.tv_sec - var->philo->start_time, var->philo->current_time.tv_usec), var->index + 1);
		pthread_mutex_lock(&(var->philo->fork[(var->index + 1) % var->philo->param[PHILO_FORKS]]));
		printf("%ld philosopher %d has taken a fork\n",
			ft_convert_sec(var->philo->current_time.tv_sec - var->philo->start_time, var->philo->current_time.tv_usec), var->index + 1);
		printf("%ld philosopher %d has started eating\n",
			ft_convert_sec(var->philo->current_time.tv_sec - var->philo->start_time, var->philo->current_time.tv_usec), var->index + 1);
		usleep(400 * 1000);
		pthread_mutex_unlock(&(var->philo->fork[(var->index + 1) % var->philo->param[PHILO_FORKS]]));
		pthread_mutex_unlock(&(var->philo->fork[var->index]));
		printf("%ld philosopher %d is sleeping\n",
			ft_convert_sec(var->philo->current_time.tv_sec - var->philo->start_time, var->philo->current_time.tv_usec), var->index + 1);
		usleep(100 * 1000);
		printf("%ld philosopher %d is thinking\n",
			ft_convert_sec(var->philo->current_time.tv_sec - var->philo->start_time, var->philo->current_time.tv_usec), var->index + 1);
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
	while (i < philo->param[PHILO_FORKS])
	{
		var[i].index = i;
		var[i].philo = philo;
		if (pthread_create(&philo->ph[i], NULL, &func, var + i) != 0)
			ft_printf("ERROR\n");
		i++;
		// usleep(100);
	}
	i = 0;
	while (i < philo->param[PHILO_FORKS])
	{
		if (pthread_join(philo->ph[i++], NULL) != 0)
			ft_printf("ERROR\n");
	}
	// i = 0;
	// while (i < philo->param[PHILO_FORKS])
	// 	pthread_mutex_destroy(&philo->fork[i++]);
}
