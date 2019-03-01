/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:13:19 by aspektor          #+#    #+#             */
/*   Updated: 2018/12/19 15:13:19 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_spec		ft_init_flag(char c, t_spec mod)
{
	if (c == '-')
		mod.l_algn = 1;
	else if (c == '+')
		mod.plus = 1;
	else if (c == '#')
		mod.format = 1;
	else if (c == ' ')
		mod.space = 1;
	else if (c == '0')
		mod.zero = 1;
	return (mod);
}

static	t_spec		ft_get_value(const char *c, t_spec mod, va_list ap,
					short is_prcsn)
{
	if (!is_prcsn && ((*c > '0' && *c <= '9') || *c == '*'))
	{
		if ((mod.width = (*c == '*') ? va_arg(ap, int) : ft_atoi(c)) < 0)
		{
			mod.l_algn = 1;
			mod.width *= -1;
		}
	}
	else
	{
		if ((mod.prcsn = *c == '*' ? va_arg(ap, int) : ft_atoi(c)) < 0)
		{
			mod.pr = 0;
			mod.prcsn = 0;
		}
		else
			mod.pr = 1;
	}
	return (mod);
}

static	t_spec		ft_get_flags(const char *c, t_spec mod, int len, va_list ap)
{
	INI(i, -1);
	while (c[i] && ++i < len)
	{
		if (c[i] == '-' || c[i] == '+' || c[i] == '#' ||
		c[i] == ' ' || c[i] == '0')
			mod = ft_init_flag(c[i], mod);
		else if ((c[i] > '0' && c[i] <= '9') || c[i] == '*')
			mod = ft_get_value(&c[i], mod, ap, 0);
		else if (c[i] == '.')
		{
			if ((c[i + 1] > '0' && c[i + 1] <= '9') || c[i + 1] == '*')
				mod = ft_get_value(&c[++i], mod, ap, 1);
			else
				mod.pr = (mod.prcsn -= mod.prcsn) - 1;
		}
		else if (c[i] == '^' && ++i)
			mod.fd = (c[i] == '*') ? va_arg(ap, int) : ft_atoi(&c[i]);
		if (c[i] > '0' && c[i] <= '9')
		{
			while (c[i + 1] >= '0' && c[i + 1] <= '9')
				i++;
		}
	}
	return (mod);
}

t_spec				ft_get_format(t_spec mod, const char *c,
					int len, va_list ap)
{
	int		i;
	int		j;

	mod = ft_get_flags(c, mod, len, ap);
	mod.c = (!is_size_mod(c[len]) && !is_flag_mod(c[len])) ? c[len] : 0;
	if (!mod.c)
		return (mod);
	i = -1;
	while (++i < len)
	{
		if (is_size_mod(c[i]) && is_right_size(mod.c, c[i], mod.size[0]))
		{
			j = 0;
			mod.size[j++] = c[i++];
			if (c[i] && is_size_mod(c[i]) && c[j - 1] == c[j])
				mod.size[j++] = c[i];
			while (j < 2)
				mod.size[j++] = '\0';
		}
	}
	return (mod);
}
