/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:36:36 by abaioumy          #+#    #+#             */
/*   Updated: 2022/06/08 21:33:01 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	ft_print_states(t_ph_var *var, int state)
{
	t_states	st;

	st.time1 = var->philo->current_time.tv_sec;
	st.time2 = var->philo->start_time;
	st.time3 = var->philo->current_time.tv_usec;
	if (state == FORK)
	{
		printf("%ld philosopher %d has taken a fork\n",
			ft_convert_sec(st.time1 - st.time2, st.time3), var->index + 1);
	}
	if (state == EAT)
	{
		printf("%ld philosopher %d has started eating\n",
			ft_convert_sec(st.time1 - st.time2, st.time3), var->index + 1);
	}
	if (state == SLEEP)
	{
		printf("%ld philosopher %d is sleeping\n",
			ft_convert_sec(st.time1 - st.time2, st.time3), var->index + 1);
	}
	if (state == THINK)
	{
		printf("%ld philosopher %d is thinking\n",
			ft_convert_sec(st.time1 - st.time2, st.time3), var->index + 1);
	}
}
