/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:54:40 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/03 16:13:21 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

// void	ft_nbr_eat(t_philo *philo)
// {
// 	// int	i;

// 	// i = 0;
// 	// if (philo->g_ac > 5)
// 	// {
// 	// 	(philo->eat_limit) = (int *)malloc(sizeof(int)
// 	// 			* philo->param[PHILO_FORKS]);
// 	// 	while (i < philo->param[PHILO_FORKS])
// 	// 	{
// 	// 		philo->eat_limit[i] = philo->nbr_eat;
// 	// 		i++;
// 	// 	}
// 	// }
// 	// else
// 	// {
// 	// 	philo->eat_limit = (int *)malloc(sizeof(int)
// 	// 			* philo->param[PHILO_FORKS]);
// 	// 	while (i < philo->param[PHILO_FORKS])
// 	// 	{
// 	// 		philo->eat_limit[i] = -1;
// 	// 		i++;
// 	// 	}
// 	// }
// }

void	ft_check_eating(t_ph_var *var)
{
	int		i;

	i = 0;
	while (i < var->philo->param[PHILO_FORKS])
	{
		pthread_mutex_lock(var->philo->eat_lock);
		if (var[i].eat_limit)
		{
			pthread_mutex_unlock(var->philo->eat_lock);
			return ;
		}
		pthread_mutex_unlock(var->philo->eat_lock);
		i++;
	}
	pthread_mutex_lock(var->philo->end_lock);
	*var->should_end = 1;
		// while (i < var->philo->param[PHILO_FORKS])
		// 			pthread_join(var->philo->ph[i++], NULL);
	// ft_free_everything(var);
}

void	ft_free_everything(t_ph_var *var)
{
	free(var->philo->param);
	free(var->philo->fork);
	free(var->philo->ph);
	free(var->philo->print_lock);
	free(var->philo->time_lock);
	free(var->philo->end_lock);
}
