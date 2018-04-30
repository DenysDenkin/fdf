/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:48:06 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/18 19:51:01 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *res)
{
	res->sharp = 0;
	res->zero = 0;
	res->plus = 0;
	res->minus = 0;
	res->space = 0;
	res->app = 0;
}

int		parse_num(const char **format)
{
	int		num;

	num = 0;
	if (!ft_isdigit(**format) || !hasdollar(*format))
		return (0);
	while (ft_isdigit(**format))
	{
		num *= 10;
		num += **format - 48;
		(*format)++;
	}
	if (**format == '$')
	{
		(*format)++;
		return (num);
	}
	else
		return (0);
}

void	va_to_num(int num, va_list *temp)
{
	int		i;

	i = -1;
	while (++i < num - 1)
		va_arg(*temp, char *);
}

int		get_arg_num(int num, va_list orig)
{
	int		i;
	int		res;
	va_list	temp;

	va_copy(temp, orig);
	i = -1;
	while (++i < num)
		res = va_arg(temp, int);
	va_end(temp);
	return (res);
}

int		get_arg(const char **format, va_list *va, va_list orig)
{
	int		num;

	num = 0;
	if (**format == '*')
		(*format)++;
	if (!ft_isdigit(**format))
		return (va_arg(*va, int));
	while (ft_isdigit(**format))
	{
		num *= 10;
		num += **format - 48;
		(*format)++;
	}
	if (**format == '$')
	{
		(*format)++;
		return (get_arg_num(num, orig));
	}
	else
		return (va_arg(*va, int));
}
