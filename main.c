/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:16:57 by abaioumy          #+#    #+#             */
/*   Updated: 2022/06/04 16:49:54 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	main(int ac, char **av)
{
	t_philo			philo;

	gettimeofday(&(philo.current_time), NULL);
	philo.start_time = philo.current_time.tv_sec;
	if (ac != 5 && ac != 6)
		return (0);
	ft_parse_param(av, ac, &philo);
	ft_create_threads(&philo);
	return (0);
}
