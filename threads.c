/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:25:35 by abaioumy          #+#    #+#             */
/*   Updated: 2022/06/23 12:39:35 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	ft_if_philo_dead(t_ph_var *var)
{
	if (var->endtime - var
		->starttime > var->philo->param[TIME_2_DIE] && var->test > 0)
	{
		return (0);
	}
	return (1);
}

void	ft_philo_b(t_ph_var *var)
{
	pthread_mutex_lock(&(var->philo
			->fork[(var->index + 1) % var->philo->param[PHILO_FORKS]]));
	pthread_mutex_lock((var->philo->print_lock));
	ft_print_states(var, FORK);
	pthread_mutex_unlock((var->philo->print_lock));
	pthread_mutex_lock((var->philo->print_lock));
	ft_print_states(var, EAT);
	pthread_mutex_unlock((var->philo->print_lock));
	ft_good_sleep(var->philo->param[TIME_2_EAT]);
	var->nbr_eat[var->index]--;
	ft_check_eating(var);
	pthread_mutex_unlock(&(var->philo
			->fork[(var->index + 1) % var->philo->param[PHILO_FORKS]]));
	var->starttime = ft_convert_sec(var->philo->current_time.tv_sec
			- var->philo->start_time, var->philo->current_time.tv_usec);
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
	while (1)
	{
		if (var->index % 2 != 0)
			usleep(300);
		gettimeofday(&(var->philo->current_time), NULL);
		pthread_mutex_lock(&(var->philo->fork[var->index]));
		pthread_mutex_lock((var->philo->print_lock));
		ft_print_states(var, FORK);
		pthread_mutex_unlock((var->philo->print_lock));
		var->endtime = ft_convert_sec(var->philo->current_time.tv_sec
				- var->philo->start_time, var->philo->current_time.tv_usec);
		if (!ft_if_philo_dead(var))
		{
			pthread_mutex_lock(var->philo->print_lock);
			printf("philosopher %d died", var->index + 1);
			ft_free_everything(var);
			exit(0);
		}
		ft_philo_b(var);
		var->test++;
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
	ft_nbr_eat(var);
	while (i < philo->param[PHILO_FORKS])
	{
		var[i].index = i;
		var[i].philo = philo;
		if (pthread_create(&philo->ph[i], NULL, &ft_philo_a, var + i) != 0)
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
