/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:54:40 by abaioumy          #+#    #+#             */
/*   Updated: 2022/06/23 12:56:00 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_nbr_eat(t_ph_var *var)
{
	int	i;

	i = 0;
	printf("%d\n", var->philo->param[NBR_FOR_PHILO_2_EAT]);
	if (var->philo->param[NBR_FOR_PHILO_2_EAT] > 0)
	{
		exit(0);
		var->nbr_eat = (int *)malloc(sizeof(int)
				* var->philo->param[PHILO_FORKS]);
		while (i < var->philo->param[PHILO_FORKS])
		{
			printf("%d\n %d \n", i, var->philo->param[PHILO_FORKS]);
			var->nbr_eat[i] = var->philo->param[NBR_FOR_PHILO_2_EAT];
			i++;
		}
	}
	else
	{
		var->nbr_eat = (int *)malloc(sizeof(int)
				* var->philo->param[PHILO_FORKS]);
		while (i < var->philo->param[PHILO_FORKS])
		{
			var->nbr_eat[i] = -1;
			i++;
		}
	}
}

void	ft_check_eating(t_ph_var *var)
{
	int	i;

	i = 0;
	while (var->nbr_eat[i])
	{
		if (var->nbr_eat[i] != 0)
			return ;
		i++;
	}
	ft_free_everything(var);
	exit(0);
}

void	ft_free_everything(t_ph_var *var)
{
	free(var->philo->ph);
	free(var->philo->fork);
	free(var->philo->print_lock);
	free(var->philo->param);
	free(var);
}
