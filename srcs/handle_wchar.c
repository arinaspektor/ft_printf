/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:08:32 by aspektor          #+#    #+#             */
/*   Updated: 2019/02/25 20:08:33 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_wsize(wchar_t ch)
{
	int size;

	size = 0;
	if (ch <= 0x7F)
		size = 1;
	else if (ch <= 0x7FF)
		size = 2;
	else if (ch <= 0xFFFF)
		size = 3;
	else if (ch <= 0x10FFFF)
		size = 4;
	if (size > MB_CUR_MAX)
		return (-1);
	return (size);
}

int		ft_wstrlen(const wchar_t *s)
{
	int len;

	len = 0;
	while (*s != L'\0')
	{
		len += ft_get_wsize(*s);
		s++;
	}
	return (len);
}

int		ft_check_wpr(const wchar_t *s, int prcsn)
{
	int size;

	size = 0;
	while (*s != L'\0' && (prcsn -= size) > 0)
	{
		size = ft_get_wsize(*s);
		s++;
	}
	return (prcsn == 0 ? 0 : prcsn + size);
}

void	ft_putwchr_fd(wchar_t ch, short size, int fd)
{
	char tmp[size];

	if (size <= MB_CUR_MAX)
	{
		if (size == 1)
			tmp[0] = ch;
		else
		{
			if (size == 2)
				tmp[0] = (ch & (0x1f << 6)) >> 6 | 0xC0;
			else
			{
				if (size == 3)
					tmp[0] = ((ch >> 12) & 0xf) | 0xE0;
				else
				{
					tmp[0] = ((ch >> 18) & 7) | 0xF0;
					tmp[1] = ((ch >> 12) & 0x3f) | 0x80;
				}
				tmp[size - 2] = ((ch >> 6) & 0x3f) | 0x80;
			}
			tmp[size - 1] = (ch & 0x3f) | 0x80;
		}
		write(fd, tmp, size);
	}
}

void	ft_putnwstr(wchar_t *s, int fd, int len)
{
	int size;

	size = 0;
	while (*s != L'\0' && (len -= (size = ft_get_wsize(*s))) >= 0)
	{
		ft_putwchr_fd(*s, size, fd);
		s++;
	}
}
