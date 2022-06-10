/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:27:55 by abaioumy          #+#    #+#             */
/*   Updated: 2022/06/09 12:05:05 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

long	ft_convert_sec(long nbr, int nbr2)
{
	return ((nbr * 1000) + (nbr2 / 1000));
}

unsigned int	ft_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_good_sleep(unsigned int time_s)
{
	struct timeval	time_n;
	unsigned int	time_ms;

	gettimeofday(&time_n, NULL);
	time_ms = (time_n.tv_sec * 1000) + (time_n.tv_usec / 1000);
	usleep(time_s * 1000 * 0.90);
	while (ft_current_time() < time_ms + time_s)
		continue ;
}
