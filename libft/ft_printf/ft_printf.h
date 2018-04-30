/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:54:28 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/19 18:51:00 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "../libft.h"

typedef struct	s_flags
{
	int			sharp;
	int			zero;
	int			minus;
	int			space;
	int			plus;
	int			app;
}				t_flags;

typedef struct	s_form
{
	t_flags		*flg;
	int			num;
	int			min_w;
	int			prec;
	char		*lmod;
	char		conv;
	int			res;
}				t_form;

typedef struct	s_opp
{
	char		*convers;
	int			(*op)(va_list *va, t_form *form);
}				t_opp;

int				ft_printf(const char *format, ...);
int				parse_num(const char **format);
t_flags			*parse_flags(const char **format);
void			parse_w(va_list *va, const char **format, t_form *form,\
		va_list orig);
void			parse_prec(va_list *va, const char **format, t_form *form,\
		va_list orig);
char			*parse_lmod(const char **format);
char			parse_conv(const char **format, t_opp *g_opptab);
void			init_flags(t_flags *res);
void			va_to_num(int num, va_list *temp);
int				get_arg(const char **format, va_list *va, va_list orig);
int				hasdollar(const char *format);

char			*dec_handler(t_form *form, intmax_t *num);
char			*unum_handler(t_form *form, uintmax_t *num);
double			double_handler(va_list *va, t_form *form);
int				string_handler(va_list *va, t_form *form);
int				wstring_handler(va_list *va, t_form *form);
int				pointer_handler(va_list *va, t_form *form);
int				int_handler(va_list *va, t_form *form);
int				octal_handler(va_list *va, t_form *form);
int				unsigned_handler(va_list *va, t_form *form);
int				hex_handler(va_list *va, t_form *form);
int				char_handler(va_list *va, t_form *form);
int				wchar_handler(va_list *va, t_form *form);
int				perc_handler(va_list *va, t_form *form);
int				e_handler(va_list *va, t_form *form);
int				f_handler(va_list *va, t_form *form);
int				g_handler(va_list *va, t_form *form);
int				a_handler(va_list *va, t_form *form);
int				n_handler(va_list *va, t_form *form);
int				binary_handler(va_list *va, t_form *form);
int				nonprint_handler(va_list *va, t_form *form);
int				date_handler(va_list *va, t_form *form);
int				time_handler(va_list *va, t_form *form);
int				mass_handler(va_list *va, t_form *form);
int				failconv_handler(const char **format, t_form *form);

void			apply_app(char **res);
void			apply_plusspace(char **res, t_form *form, char symb);
void			apply_precision(char **res, t_form *form);
void			apply_precisions(char **res, t_form *form);
void			apply_blanks(char **res, t_form *form, int minus);
void			apply_blanksw(char **res, t_form *form, int minus);
void			apply_zero(char **res, t_form *form);
#endif
