/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:08:02 by abaioumy          #+#    #+#             */
/*   Updated: 2022/06/28 10:21:32 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_parse_param(char **av, int ac, t_philo *philo)
{
	int	i;
	int	j;

	philo->g_ac = ac;
	i = 1;
	j = 0;
	philo->param = (int *)malloc(sizeof(int) * ac);
	while (av[i])
		philo->param[j++] = ft_atoi(av[i++]);
	if (ac == 5)
	{
		j++;
		philo->param[ac - 1] = 0;
	}
	philo->nbr_eat = philo->param[ac - 2];
}
