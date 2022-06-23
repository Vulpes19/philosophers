/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:08:02 by abaioumy          #+#    #+#             */
/*   Updated: 2022/06/23 12:58:22 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_parse_param(char **av, int ac, t_philo *philo)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	philo->param = (int *)malloc(sizeof(int) * 6);
	while (av[i])
		philo->param[j++] = ft_atoi(av[i++]);
	j++;
	if (ac > 5)
		philo->param[j] = 0;
}
