/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:33:13 by aspektor          #+#    #+#             */
/*   Updated: 2018/11/06 13:33:14 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	unsigned long	res;
	int				sn;

	while (ft_isspace(*str) || *str == '0')
		str++;
	sn = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sn = -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (res < 1844674407370955161 || (sn == -1 && res < 922337203685477580))
			res = res * 10 + (*str - '0');
		else
			return ((sn == -1) ? 0 : -1);
		str++;
	}
	return ((int)res * sn);
}
