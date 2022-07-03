/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:31:17 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/03 14:56:00 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

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
