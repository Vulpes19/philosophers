/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:08:02 by abaioumy          #+#    #+#             */
/*   Updated: 2022/05/23 14:57:09 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_parse_param(char **av, int ac, t_philo *philo)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	philo->param = (int *)malloc(sizeof(int) * ac);
	while (av[i])
		philo->param[j++] = ft_atoi(av[i++]);
}
