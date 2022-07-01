/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:36:36 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/01 15:38:22 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_print_states(t_ph_var *var, int state)
{
	long	st;
	long		curr_time;

	// st.time1 = var->last_meal.tv_sec;
	st = var->philo->start_time;
	// st.time3 = var->last_meal.tv_usec;
	curr_time = ft_current_time();
	if (state == FORK)
	{
		printf("%ld ms philosopher %d has taken a fork\n",
		curr_time - st, var->index + 1);
	}
	if (state == EAT)
	{
		printf("%ld ms philosopher %d has started eating\n",
			curr_time - st, var->index + 1);
	}
	if (state == SLEEP)
	{
		printf("%ld ms philosopher %d is sleeping\n",
			curr_time - st, var->index + 1);
	}
	if (state == THINK)
	{
		printf("%ld ms philosopher %d is thinking\n",
			curr_time - st, var->index + 1);
	}
	// exit(0);
}
