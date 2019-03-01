/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:15:30 by aspektor          #+#    #+#             */
/*   Updated: 2019/01/08 17:15:30 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_FORMAT_H
# define _FT_FORMAT_H

typedef	struct	s_form {
	char		fc;
	char		fsize[3];
	int			flen;
}				t_form;

static t_form	g_format[] =
{
	{'p', "0x", 2},
	{'x', "0x", 2},
	{'X', "0X", 2},
	{'b', "0b", 2},
	{'B', "0B", 2},
};

#endif
