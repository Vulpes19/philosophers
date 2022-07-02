/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:16:57 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/02 18:14:02 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	main(int ac, char **av)
{
	t_philo			philo;
	t_ph_var		var;

	philo.start_time = ft_current_time();
	if (!ft_handle_errors(ac, NBR_ARGS))
		return (0);
	if (!ft_parse_param(av, ac, &philo))
		return (0);
	ft_create_threads(&philo, &var);
	// system("leaks philo");
	return (0);
}
