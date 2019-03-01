/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:06:47 by aspektor          #+#    #+#             */
/*   Updated: 2019/01/18 18:06:48 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_itoa_base(size_t nb, short base, short is_x)
{
	char	*base_arr;
	char	x;

	x = '0';
	if (is_x)
		base_arr = "0123456789ABCDEF";
	else
		base_arr = "0123456789abcdef";
	if (nb / base > 0)
		ft_itoa_base(nb / base, base, is_x);
	x = base_arr[nb % base];
	write(1, &x, 1);
}
