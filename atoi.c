/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:04:54 by abaioumy          #+#    #+#             */
/*   Updated: 2022/07/02 16:20:09 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	result;
	int					sign;

	result = 0;
	i = 0;
	sign = 1;
	// while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	// 	i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	// if (result >= (unsigned long long)9223372036854775807 + 1 && sign == -1)
	// 	return (0);
	// if (result > 9223372036854775807 && sign == 1)
	// 	return (-1);
	return (result * sign);
}
