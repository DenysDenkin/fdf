/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:06:36 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/11 18:09:39 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			unsigned_handler(va_list *va, t_form *form)
{
	char		*res;
	uintmax_t	num;
	int			i;

	num = va_arg(*va, uintmax_t);
	res = unum_handler(form, &num);
	apply_precision(&res, form);
	if (form->flg->minus == 1)
		apply_blanks(&res, form, 1);
	else if (form->flg->zero == 1 && form->prec == -1)
		apply_zero(&res, form);
	else
		apply_blanks(&res, form, 0);
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return (i);
}
