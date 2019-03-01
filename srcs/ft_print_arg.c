/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:24:12 by aspektor          #+#    #+#             */
/*   Updated: 2019/01/24 18:24:13 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_format.h"

static void		ft_put_sign(int fd, short neg, short plus, short space)
{
	if (neg)
		write(fd, "-", 1);
	else if (plus)
		write(fd, "+", 1);
	else if (space)
		write(fd, " ", 1);
}

static void		ft_print_flt(t_spec mod)
{
	INI2(c, 0, tmp, mod.prcsn);
	ft_put_sign(mod.fd, (mod.type.db < 0 || 1.0 / mod.type.db == 1.0 / -0.0),
	mod.plus, mod.space);
	if (mod.type.db != mod.type.db || ISINF(mod.type.db))
		write(mod.fd, mod.type.db != mod.type.db ? "nan" : "inf", 3);
	else
	{
		mod.type.db = POS(mod.type.db);
		if (mod.zero && !mod.l_algn && mod.width)
			ft_handle_width(mod);
		ft_itoa_base((size_t)mod.type.db, 10, 0);
		if (mod.prcsn > 0 || (mod.format && !mod.prcsn))
		{
			write(mod.fd, ".", 1);
			while (tmp-- > 0)
			{
				mod.type.db = (mod.type.db - (size_t)mod.type.db) / 0.1L;
				if (!tmp && mod.prcsn > 7 && !(mod.prcsn % 2) &&
				NEXT(mod.type.db) >= 5)
					mod.type.db += 0.5L;
				c = '0' + (int)mod.type.db;
				write(mod.fd, &c, 1);
			}
		}
	}
}

static void		ft_print_nbr(t_spec mod)
{
	if (mod.c == 'd' || mod.c == 'i')
	{
		ft_put_sign(mod.fd, mod.type.i < 0, mod.plus, mod.space);
		if (mod.type.i < 0)
			mod.type.ui = mod.type.i * -1;
	}
	else if (mod.c == 'p')
		write(mod.fd, "0x", 2);
	else if (mod.format && (mod.c == 'o' || mod.c == 'O'))
		write(mod.fd, "0", 1);
	else if (mod.format && mod.type.ui)
		write(mod.fd, g_format[mod.wsize].fsize, g_format[mod.wsize].flen);
	if (!mod.type.ui && mod.pr == -1)
		return ;
	if (mod.zero && !mod.l_algn && mod.width)
		ft_handle_width(mod);
	while (mod.prcsn-- > 0)
		write(mod.fd, "0", 1);
	if (!mod.type.ui && mod.format && (mod.c == 'o' || mod.c == 'O'))
		return ;
	ft_itoa_base(mod.type.ui, mod.base, (mod.c == 'X'));
}

static void		ft_print_chr(t_spec mod)
{
	if (mod.zero && !mod.l_algn && mod.width)
		ft_handle_width(mod);
	if (mod.c == 's' || mod.c == 'S')
	{
		if (!mod.type.ptr)
			write(mod.fd, "(null)", mod.len);
		else if (!mod.wsize)
			write(mod.fd, mod.type.ptr, mod.len);
		else
			ft_putnwstr((wchar_t *)mod.type.ptr, mod.fd, mod.len);
	}
	else
	{
		if (mod.wsize > 0)
			ft_putwchr_fd(mod.type.w, mod.wsize, mod.fd);
		else
			write(mod.fd, &mod.type.uch, 1);
	}
}

void			ft_print_arg(t_spec mod)
{
	if (is_nbr_mod(mod.c))
	{
		if (mod.c == 'f' || mod.c == 'F')
			ft_print_flt(mod);
		else
			ft_print_nbr(mod);
	}
	else
		ft_print_chr(mod);
}
