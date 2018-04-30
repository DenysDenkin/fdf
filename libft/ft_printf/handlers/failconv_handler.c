/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failconv_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:38:39 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/12 14:43:17 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	conv_put(char *res, char c, int minus)
{
	if (minus == 0)
	{
		ft_putstr(res);
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		ft_putstr(res);
	}
}

int			failconv_handler(const char **format, t_form *form)
{
	char	c;
	int		i;
	char	*res;

	if (!**format)
		return (0);
	c = **format;
	(*format)++;
	i = 1;
	res = NULL;
	if (form->min_w > 1)
	{
		i = form->min_w;
		res = (char *)malloc(sizeof(char) * i);
		res[i] = 0;
		(form->flg->zero == 0) ? ft_memset(res, ' ', i - 1) :\
				ft_memset(res, '0', i - 1);
	}
	conv_put(res, c, form->flg->minus);
	ft_strdel(&res);
	return (i);
}
