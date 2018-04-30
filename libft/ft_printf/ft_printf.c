/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:08:36 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/18 19:55:37 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_opp.h"

static void			free_form(t_form **form)
{
	if (!(*form))
		return ;
	if ((*form)->flg)
		free((*form)->flg);
	if ((*form)->lmod)
		free((*form)->lmod);
	free(*form);
	*form = NULL;
}

t_form				*parse_form(const char **format, va_list *argp,\
		int *res, va_list orig)
{
	t_form *form;

	form = (t_form *)malloc(sizeof(t_form));
	form->num = parse_num(format);
	form->flg = parse_flags(format);
	parse_w(argp, format, form, orig);
	parse_prec(argp, format, form, orig);
	form->lmod = parse_lmod(format);
	form->res = *res;
	form->conv = parse_conv(format, g_opptab);
	return (form);
}

static const char	*main_handler(const char *format, va_list *argp,\
		int *res, va_list orig)
{
	t_form		*form;
	va_list		temp;
	int			i;

	i = 0;
	form = parse_form(&format, argp, res, orig);
	while (g_opptab[i].convers && form->conv != g_opptab[i].convers[0])
		i++;
	if (form->conv == 0)
		*res += failconv_handler(&format, form);
	else if (g_opptab[i].convers != NULL)
	{
		if (form->num == 0)
			*res += g_opptab[i].op(argp, form);
		else
		{
			va_copy(temp, orig);
			va_to_num(form->num, &temp);
			*res += g_opptab[i].op(&temp, form);
			va_end(temp);
		}
	}
	free_form(&form);
	return (format);
}

static int			minift_printf(const char *format, va_list *argp)
{
	int		res;
	va_list temp;

	va_copy(temp, *argp);
	res = 0;
	while (*format)
	{
		if (*format == '%')
			format = main_handler(format + 1, argp, &res, temp);
		else
		{
			ft_putchar(*format);
			format++;
			res++;
		}
	}
	va_end(temp);
	return (res);
}

int					ft_printf(const char *format, ...)
{
	va_list		argp;
	int			res;

	va_start(argp, format);
	res = minift_printf(format, &argp);
	va_end(argp);
	return (res);
}
