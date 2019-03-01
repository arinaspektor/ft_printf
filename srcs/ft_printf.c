/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:30:18 by aspektor          #+#    #+#             */
/*   Updated: 2018/12/05 19:30:19 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_spec	ft_fzero(void)
{
	t_spec mod;

	mod.len = 0;
	mod.width = 0;
	mod.prcsn = 0;
	mod.pr = 0;
	mod.l_algn = 0;
	mod.plus = 0;
	mod.zero = 0;
	mod.base = 10;
	mod.format = 0;
	mod.space = 0;
	mod.wsize = 0;
	mod.fd = 1;
	mod.size[0] = '\0';
	mod.size[1] = '\0';
	mod.size[2] = '\0';
	mod.c = 0;
	return (mod);
}

void			ft_handle_width(t_spec mod)
{
	int		i;
	char	c;

	i = mod.width;
	c = (mod.zero && !mod.l_algn) ? '0' : ' ';
	while (i-- > 0)
		write(mod.fd, &c, 1);
}

int				ft_get_res(const char *format, const char *tmp,
				int tlen, va_list ap)
{
	t_spec		mod;
	int			res;

	mod = ft_fzero();
	mod = ft_get_format(mod, tmp, tlen, ap);
	mod = ft_get_arg(mod, ap);
	if (mod.len == -1)
		return (-1);
	res = ft_strlen(format) - ft_strlen(tmp) - 1;
	write(1, format, res);
	if (!mod.c)
		return (res);
	mod.width = mod.width <= mod.len ? 0 : mod.width - mod.len;
	if (!mod.zero && !mod.l_algn && mod.width)
		ft_handle_width(mod);
	ft_print_arg(mod);
	if (mod.l_algn && mod.width)
		ft_handle_width(mod);
	return (res + mod.len + mod.width);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*tmp;
	int			res;
	int			arglen;
	int			i;

	va_start(ap, format);
	res = 0;
	while (*format && (tmp = ft_strchr(format, '%')) && tmp++)
	{
		i = 0;
		while (is_flag_mod(tmp[i]) || is_size_mod(tmp[i]))
			i++;
		if ((arglen = ft_get_res(format, tmp, i, ap)) == -1)
			return (-1);
		format = tmp[i] ? &tmp[++i] : &tmp[i];
		res += arglen;
	}
	if (*format)
	{
		write(1, format, (i = ft_strlen(format)));
		res += i;
	}
	va_end(ap);
	return (res);
}
