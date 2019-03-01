/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:03:21 by aspektor          #+#    #+#             */
/*   Updated: 2018/12/12 20:03:21 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag_mod(char c)
{
	return (c == '+' || c == ' ' || c == '-' ||
		(c >= '0' && c <= '9') || c == '*' ||
		c == '0' || c == '#' || c == '.' || c == '^');
}

int		is_size_mod(char c)
{
	return (c == 'l' || c == 'h' || c == 'j' || c == 'z' || c == 'L');
}

int		is_nbr_mod(char c)
{
	return (c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'U' ||
	c == 'o' || c == 'O' || c == 'x' || c == 'X' || c == 'f' ||
	c == 'F' || c == 'b' || c == 'B');
}

int		is_right_size(char c, char sz, char sz1)
{
	return (
		((c == 'c' || c == 's') && (sz == 'l' || sz == 'h')) ||
		((c == 'f' || c == 'F') && sz == 'L') ||
		((c == 'd' || c == 'i' || c == 'u' ||
		c == 'U' || c == 'o' || c == 'O' ||
		c == 'x' || c == 'X' || c == 'b' || c == 'B') && sz1 != 'l'));
}
