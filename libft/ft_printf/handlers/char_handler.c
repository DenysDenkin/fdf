/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:58:22 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/12 14:53:45 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	putres(char *res, char c, int minus)
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

int			char_handler(va_list *va, t_form *form)
{
	int		i;
	char	*res;

	if (form->lmod && ft_strcmp(form->lmod, "l") == 0)
		return (wchar_handler(va, form));
	res = NULL;
	i = 1;
	if (form->min_w > 1)
	{
		i = form->min_w;
		res = (char *)malloc(sizeof(char) * i);
		res[i] = 0;
		(form->flg->zero == 0) ? ft_memset(res, ' ', i - 1)\
						: ft_memset(res, '0', i - 1);
	}
	putres(res, (char)va_arg(*va, int), form->flg->minus);
	ft_strdel(&res);
	return (i);
}
