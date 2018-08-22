/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 07:12:57 by rdiederi          #+#    #+#             */
/*   Updated: 2018/08/17 14:49:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdint.h>

typedef struct	s_flagtype
{
	int		flagzero;
	int		flagplus;
	int		flagminus;
	int		flagspace;
	int		flaghtag;
	int		flaghh;
	int		flagh;
	int		flagll;
	int		flagl;
	int		flagj;
	int		flagz;
	int		min;
	int		prec;
	int		prec1;
	int		error;
	int		ret;
	int		type;
	int		print;
	char	*base;
}				t_flag;

size_t			ft_bit_len(wchar_t c);
void			ft_putstr_uni(wchar_t *s, t_flag lst, int len);
void			left_signbase(t_flag lst, int len, intmax_t nb, int i);
void			right_margingbase(t_flag lst, size_t len);
t_flag			left_margingbase(t_flag lst, int i, intmax_t nb, int len);
void			conv_str(char **nb, t_flag lst);
void			conv_struni(wchar_t **nb, t_flag lst);
void			left_sign(t_flag lst, int len, intmax_t nb);
void			right_marging(t_flag lst, size_t len);
t_flag			left_marging(t_flag lst, int i, intmax_t nb);
size_t			ft_putbuffer(char *s, int c, int init);
void			ft_printf_nbr(va_list ap, t_flag lst);
void			ft_printf_base(va_list ap, t_flag lst);
void			ft_printf_stringuni(wchar_t *s, t_flag lst);
void			ft_printf_string(va_list ap, t_flag lst);
size_t			ft_buffer(char *s, size_t len, int c);
t_flag			ft_putchar_uni(wchar_t c, t_flag lst);
void			ft_putchar_uni2(wchar_t c);
t_flag			ft_printf_putchar(va_list ap, t_flag lst);
t_flag			ft_type(va_list ap, t_flag lst);
t_flag			ft_print_error(char *tmp, t_flag lst, const char *fmt);
t_flag			ft_check_fmt(const char *fmt, va_list ap);
t_flag			ft_find_flag2(t_flag lst, int j, const char *fmt);
int				ft_printf(const char *format, ...);

#endif
