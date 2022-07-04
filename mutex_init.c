/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:31:17 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/03 21:22:24 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	ft_check_eat_limit(t_ph_var *var)
{
	if (var->eat_limit > 0)
		return (1);
	else
		return (0);
}

void	ft_mutex_init(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_init((philo->print_lock), NULL);
	pthread_mutex_init((philo->time_lock), NULL);
	pthread_mutex_init((philo->eat_lock), NULL);
	pthread_mutex_init((philo->end_lock), NULL);
	while (i < philo->param[PHILO_FORKS])
		pthread_mutex_init(&(philo->fork[i++]), NULL);
}
