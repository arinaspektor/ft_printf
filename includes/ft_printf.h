/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspektor <aspektor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:37:06 by aspektor          #+#    #+#             */
/*   Updated: 2018/12/05 19:37:06 by aspektor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

# define POS(x) ((x) < 0 ? -(x) : (x))
# define ROUND(x, y) (x * y + (x > 0 ? 0.5 : -0.5)) / y;
# define ISINF(x) (x == 1.0 / 0.0 || x == 1.0 / -0.0)

# define INI(a, av) int a = av;
# define INI2(a, av, b, bv) int a = av; int b = bv;
# define NEXT(a) (a - (int)a) / 0.1L

typedef struct			s_spec
{
	int					width;
	int					len;
	int					prcsn;
	int					fd;
	short				pr;
	short				zero;
	short				l_algn;
	short				plus;
	short				space;
	short				format;
	short				base;
	short				wsize;
	char				size[3];
	unsigned char		c;
	union
	{
		unsigned char	uch;
		wchar_t			w;
		void			*ptr;
		ssize_t			i;
		size_t			ui;
		long double		db;
	}					type;
}						t_spec;

int						ft_printf(const char *format, ...);
t_spec					ft_get_format(t_spec mod, const char *c,
						int len, va_list ap);
t_spec					ft_get_arg(t_spec mod, va_list ap);
void					ft_print_arg(t_spec mod);
void					ft_handle_width(t_spec mod);

t_spec					ft_get_uint(t_spec mod, va_list ap);
t_spec					ft_get_int(t_spec mod, va_list ap);
t_spec					ft_get_float(t_spec mod, va_list ap);

int						is_flag_mod(char c);
int						is_nbr_mod(char c);
int						is_size_mod(char c);
int						is_right_size(char c, char sz, char sz1);

int						ft_get_wsize(wchar_t ch);
int						ft_wstrlen(const wchar_t *s);
void					ft_putwchr_fd(wchar_t ch, short size, int fd);
void					ft_putnwstr(wchar_t *s, int fd, int len);
int						ft_check_wpr(const wchar_t *s, int prcsn);

char					*ft_strchr(const char *s, int c);
int						ft_nbr_len(size_t n, short base);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strlen(const char *s);
int						ft_atoi(const char *str);
void					ft_itoa_base(size_t nb, short base, short is_x);

#endif
