/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:54:40 by abaioumy          #+#    #+#             */
/*   Updated: 2022/06/29 11:54:43 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_nbr_eat(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->g_ac > 5)
	{
		(philo->eat_limit) = (int *)malloc(sizeof(int)
				* philo->param[PHILO_FORKS]);
		while (i < philo->param[PHILO_FORKS])
		{
			philo->eat_limit[i] = philo->nbr_eat;
			i++;
		}
	}
	else
	{
		philo->eat_limit = (int *)malloc(sizeof(int)
				* philo->param[PHILO_FORKS]);
		while (i < philo->param[PHILO_FORKS])
		{
			philo->eat_limit[i] = -1;
			i++;
		}
	}
}
// void	ft_nbr_eat(t_philo philo, t_ph_var *var)
// {
// 	int	i;

// 	i = 0;
// 	if (philo.g_ac > 5)
// 	{
// 		(var->eat_limit) = (int *)malloc(sizeof(int)
// 				* philo.param[PHILO_FORKS]);
// 		while (i < philo.param[PHILO_FORKS])
// 		{
// 			var->eat_limit[i] = philo.nbr_eat;
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		var->eat_limit = (int *)malloc(sizeof(int)
// 				* philo.param[PHILO_FORKS]);
// 		while (i < philo.param[PHILO_FORKS])
// 		{
// 			var->eat_limit[i] = -1;
// 			i++;
// 		}
// 	}
// }

void	ft_check_eating(t_ph_var *var)
{
	int	i;

	i = 0;
	while (i < var->philo->param[PHILO_FORKS])
	{
		if (var->philo->eat_limit[i])
			return ;
		i++;
	}
	ft_free_everything(var);
	exit(0);
}
// void	ft_check_eating(t_ph_var *var)
// {
// 	int	i;

// 	i = 0;
// 	while (i < var->philo->param[PHILO_FORKS])
// 	{
// 		if (var->eat_limit[i])
// 			return ;
// 		i++;
// 	}
// 	ft_free_everything(var);
// 	exit(0);
// }

void	ft_free_everything(t_ph_var *var)
{
	free(var->philo->param);
	free(var->philo->fork);
	free(var->philo->ph);
	free(var->philo->print_lock);
	exit(0);
	// free(var);
}
