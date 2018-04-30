/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:31:50 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/18 19:53:57 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		parse_conv(const char **format, t_opp *g_opptab)
{
	char	conv;
	int		i;

	conv = **format;
	i = 0;
	while (g_opptab[i].convers && (g_opptab[i].convers[0] != conv))
		i++;
	if (g_opptab[i].convers == NULL)
		return (0);
	(*format)++;
	return (conv);
}

t_flags		*parse_flags(const char **format)
{
	t_flags *res;

	if (!(res = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	init_flags(res);
	while (**format)
	{
		if (**format == '#')
			res->sharp = 1;
		else if (**format == ' ')
			res->space = 1;
		else if (**format == '0')
			res->zero = 1;
		else if (**format == '-')
			res->minus = 1;
		else if (**format == '+')
			res->plus = 1;
		else if (**format == '\'')
			res->app = 1;
		else
			return (res);
		(*format)++;
	}
	return (res);
}

void		parse_w(va_list *va, const char **format, t_form *form,\
		va_list orig)
{
	form->min_w = 0;
	if (ft_isdigit(**format) && (form->min_w = 0) == 0)
	{
		while (ft_isdigit(**format))
		{
			form->min_w *= 10;
			form->min_w += **format - 48;
			(*format)++;
		}
	}
	else if (**format == '*')
		form->min_w = get_arg(format, va, orig);
	if (form->min_w < 0)
	{
		form->flg->minus = 1;
		form->min_w *= -1;
	}
}

void		parse_prec(va_list *va, const char **format,\
		t_form *form, va_list orig)
{
	form->prec = -1;
	if (**format == '.')
	{
		form->prec = 0;
		(*format)++;
		if (ft_isdigit(**format))
			while (ft_isdigit(**format))
			{
				form->prec *= 10;
				form->prec += **format - 48;
				(*format)++;
			}
		else if (**format == '*')
			form->prec = get_arg(format, va, orig);
		form->prec = (form->prec < 0) ? -1 : form->prec;
	}
}

char		*parse_lmod(const char **format)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 3);
	ft_memset(res, 0, 3);
	if (**format == 'h' || **format == 'l' || **format == 'j'\
			|| **format == 'z' || **format == 'L')
		res[0] = **format;
	else
	{
		free(res);
		return (NULL);
	}
	(*format)++;
	if ((res[0] == 'h' && **format == 'h') || (res[0] == 'l' \
				&& **format == 'l'))
		res[1] = **format;
	else
		return (res);
	(*format)++;
	return (res);
}
