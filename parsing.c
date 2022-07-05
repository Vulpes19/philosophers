/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:08:02 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/04 23:02:41 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

static int	ft_check_av(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '0')
		return (0);
	while (av[i])
	{
		if (!(av[i] >= 48 && av[i] <= 57) && av[i] != 43)
			return (0);
		i++;
	}
	return (1);
}

int	ft_handle_errors(int ac, int nbr)
{
	if (nbr == NBR_ARGS)
	{
		if (ac != 5 && ac != 6)
		{
			printf("[nbr_of_philos] [time_to_die] ");
			printf("[time_to_eat] [time_to_sleep] [nbr_of_times_philos_eat]\n");
			printf("the final one is optional\n");
			return (0);
		}
		return (1);
	}
	if (nbr == TYPE_ARGS)
	{
		printf("the arguments must be positive numbers!\n");
		return (0);
	}
	return (1);
}

int	ft_parse_param(char **av, int ac, t_philo *philo)
{
	int	i;
	int	j;

	philo->g_ac = ac;
	i = 1;
	j = 0;
	philo->param = (int *)malloc(sizeof(int) * ac);
	while (av[i])
	{
		if (ft_check_av(av[i]))
			philo->param[j++] = ft_atoi(av[i++]);
		else
		{
			ft_handle_errors(ac, TYPE_ARGS);
			return (0);
		}
	}
	if (ac == 5)
	{
		j++;
		philo->param[ac - 1] = 0;
	}
	philo->nbr_eat = philo->param[ac - 2];
	return (1);
}
