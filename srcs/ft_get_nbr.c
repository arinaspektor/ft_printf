/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:09:29 by aspektor          #+#    #+#             */
/*   Updated: 2019/01/18 18:09:30 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	pwr(size_t x, int y)
{
	size_t tmp;

	if (y == 0)
		return (1);
	tmp = pwr(x, y / 2);
	if (y % 2 == 0)
		return (tmp * tmp);
	else
		return (x * tmp * tmp);
}

t_spec			ft_get_float(t_spec mod, va_list ap)
{
	if (!ft_strcmp(mod.size, "L"))
		mod.type.db = va_arg(ap, long double);
	else
		mod.type.db = (long double)va_arg(ap, double);
	if (mod.type.db != mod.type.db || mod.type.db == 1.0 / 0.0 ||
		mod.type.db == 1.0 / -0.0)
	{
		mod.zero = 0;
		mod.len = 3;
	}
	else
	{
		if (!mod.pr)
			mod.prcsn = 6;
		if (mod.type.db && mod.prcsn < 20)
			mod.type.db = ROUND(mod.type.db, pwr(10, mod.prcsn));
		mod.len = ft_nbr_len(POS(mod.type.db), 10) + mod.prcsn +
		(mod.prcsn > 0) + (mod.format && !mod.prcsn);
	}
	mod.len += (mod.type.db < 0 || mod.plus || mod.space ||
	(1.0 / mod.type.db == 1.0 / -0.0));
	return (mod);
}

t_spec			ft_get_uint(t_spec mod, va_list ap)
{
	if (mod.c == 'b' || mod.c == 'B')
		mod.base = 2;
	else if (mod.c != 'u' && mod.c != 'U')
		mod.base = (mod.c == 'o' || mod.c == 'O') ? 8 : 16;
	if (mod.c == 'U' || mod.c == 'O' || mod.c == 'p' ||
	!ft_strcmp(mod.size, "l") || !ft_strcmp(mod.size, "j"))
		mod.type.ui = va_arg(ap, unsigned long int);
	else if (!ft_strcmp(mod.size, "ll"))
		mod.type.ui = va_arg(ap, unsigned long long int);
	else if (!ft_strcmp(mod.size, "h"))
		mod.type.ui = (unsigned short int)va_arg(ap, int);
	else if (!ft_strcmp(mod.size, "hh"))
		mod.type.ui = (unsigned char)va_arg(ap, unsigned int);
	else if (!ft_strcmp(mod.size, "z"))
		mod.type.ui = va_arg(ap, ssize_t);
	else
		mod.type.ui = va_arg(ap, unsigned int);
	mod.len = ((mod.pr && !mod.prcsn && !mod.type.ui) ? 0 :
	ft_nbr_len(mod.type.ui, mod.base));
	if (mod.pr == 1)
		mod.prcsn = (mod.prcsn > mod.len ? mod.prcsn - mod.len : 0);
	return (mod);
}

t_spec			ft_get_int(t_spec mod, va_list ap)
{
	if (!ft_strcmp(mod.size, "l") || !ft_strcmp(mod.size, "j"))
		mod.type.i = va_arg(ap, long int);
	else if (!ft_strcmp(mod.size, "ll"))
		mod.type.i = va_arg(ap, long long int);
	else if (!ft_strcmp(mod.size, "h"))
		mod.type.i = (short int)va_arg(ap, int);
	else if (!ft_strcmp(mod.size, "hh"))
		mod.type.i = (char)va_arg(ap, int);
	else if (!ft_strcmp(mod.size, "z"))
		mod.type.i = va_arg(ap, size_t);
	else
		mod.type.i = va_arg(ap, int);
	mod.base = 10;
	mod.len = (mod.pr && !mod.prcsn && !mod.type.ui) ? 0 :
	ft_nbr_len(POS(mod.type.i), 10);
	if (mod.pr == 1)
		mod.prcsn = (mod.prcsn > mod.len ? mod.prcsn - mod.len : 0);
	mod.len += (mod.prcsn + (mod.type.i < 0 || mod.plus || mod.space));
	return (mod);
}
