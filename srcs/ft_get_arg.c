/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:16:43 by aspektor          #+#    #+#             */
/*   Updated: 2019/01/24 17:16:43 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_format.h"

static	t_spec		ft_get_nbr(t_spec mod, va_list ap)
{
	INI(i, 0);
	if (mod.pr && mod.c != 'f' && mod.c != 'F')
		mod.zero = 0;
	if (mod.c == 'f' || mod.c == 'F' || mod.c == 'd' || mod.c == 'i')
		mod = (mod.c == 'd' || mod.c == 'i') ? ft_get_int(mod, ap) :
		ft_get_float(mod, ap);
	else
	{
		mod = ft_get_uint(mod, ap);
		if (mod.format && (mod.c == 'o' || mod.c == 'O'))
		{
			mod.len += ((!mod.pr || mod.prcsn) && !mod.type.ui ? 0 : 1);
			if (mod.prcsn && mod.type.ui)
				mod.prcsn -= 1;
		}
		else if ((mod.format && mod.type.ui) || mod.c == 'p')
		{
			while (g_format[i].fc != mod.c && i < 5)
				i++;
			mod.len += g_format[i].flen;
			mod.wsize = i;
		}
		mod.len += mod.prcsn;
	}
	return (mod);
}

static	t_spec		ft_get_str(t_spec mod, va_list ap)
{
	if (mod.c == 'S' || !ft_strcmp(mod.size, "l"))
	{
		if ((mod.type.ptr = va_arg(ap, wchar_t *)))
		{
			if ((mod.wsize = ft_get_wsize(*(wchar_t *)mod.type.ptr)) == -1)
			{
				mod.len = -1;
				return (mod);
			}
			mod.len = mod.pr == -1 ? 0 : ft_wstrlen((wchar_t *)mod.type.ptr);
			if (mod.pr == 1 && mod.len > mod.prcsn)
				mod.prcsn -= ft_check_wpr((wchar_t *)mod.type.ptr, mod.prcsn);
		}
	}
	else
	{
		if ((mod.type.ptr = va_arg(ap, char *)))
			mod.len = mod.pr == -1 ? 0 : ft_strlen(mod.type.ptr);
	}
	if (!mod.type.ptr)
		mod.len = mod.pr == -1 ? 0 : 6;
	if (mod.pr == 1 && mod.len > mod.prcsn)
		mod.len = mod.prcsn;
	return (mod);
}

static	t_spec		ft_get_chr(t_spec mod, va_list ap)
{
	if (!ft_strcmp(mod.size, "l") || mod.c == 'C')
	{
		mod.type.w = (wchar_t)va_arg(ap, wint_t);
		if ((mod.wsize = ft_get_wsize(mod.type.w)) == -1)
		{
			mod.len = -1;
			return (mod);
		}
		mod.len = mod.wsize;
	}
	else
	{
		mod.type.uch = (mod.c == 'c') ? (unsigned char)va_arg(ap, int) : mod.c;
		mod.len = 1;
	}
	return (mod);
}

t_spec				ft_get_arg(t_spec mod, va_list ap)
{
	if (mod.c == 's' || mod.c == 'S')
		mod = ft_get_str(mod, ap);
	else if (is_nbr_mod(mod.c))
		mod = ft_get_nbr(mod, ap);
	else
		mod = ft_get_chr(mod, ap);
	return (mod);
}
