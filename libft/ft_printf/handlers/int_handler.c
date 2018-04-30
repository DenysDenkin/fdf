/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:19:01 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/17 20:36:09 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			int_handler(va_list *va, t_form *form)
{
	char		*res;
	intmax_t	num;
	int			i;

	num = va_arg(*va, intmax_t);
	if (num == 0 && form->prec == 0)
		res = ft_strdup("");
	else
		res = dec_handler(form, &num);
	(form->flg->app == 1) ? apply_app(&res) : 1;
	apply_precision(&res, form);
	if (form->flg->minus == 0 && form->flg->zero == 1 && form->prec == -1)
		apply_zero(&res, form);
	if (form->flg->plus == 1)
		apply_plusspace(&res, form, '+');
	else if (form->flg->space == 1)
		apply_plusspace(&res, form, ' ');
	if (form->flg->minus == 1)
		apply_blanks(&res, form, 1);
	apply_blanks(&res, form, 0);
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return (i);
}
