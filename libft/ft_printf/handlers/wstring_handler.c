/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstring_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:54:10 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/12 14:45:06 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	intsize(int ch)
{
	int i;

	i = 0;
	if (ch < 0)
		ch = -ch - 1;
	while (ch > 0)
	{
		i++;
		ch = ch >> 1;
	}
	if (i <= 7)
		return (1);
	if (i <= 11)
		return (2);
	if (i <= 16)
		return (3);
	return (4);
}

static int	wstr_size(wchar_t *s)
{
	int		res;

	res = 0;
	while (*s)
		res += intsize(*s++);
	return (res);
}

int			wstring_handler(va_list *va, t_form *form)
{
	wchar_t *s;
	char	*res;
	int		i;
	int		j;
	int		l;

	s = va_arg(*va, wchar_t *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	j = 0;
	l = (form->prec != -1) ? ft_min(wstr_size(s), form->prec) : wstr_size(s);
	res = (char *)malloc(sizeof(char) * (l + 1));
	ft_memset(res, 0, l + 1);
	while (s[i] && l - j > 0)
		j += ft_unictoa((res + j), s[i++], l - j);
	(form->flg->minus == 0 && form->flg->zero == 1) ? apply_zero(&res, form) :\
					apply_blanksw(&res, form, form->flg->minus);
	i = ft_strlen(res);
	write(1, res, i);
	free(res);
	return (i);
}
