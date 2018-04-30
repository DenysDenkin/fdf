/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:45:03 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/17 20:36:27 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		f_handler(va_list *va, t_form *form)
{
	double	d;
	int		prec;
	char	*res;

	d = double_handler(va, form);
	prec = (form->prec == -1) ? 6 : form->prec;
	res = ft_dtoa(d, prec);
	(form->flg->app == 1) ? apply_app(&res) : 1;
	if (form->flg->minus == 1)
		apply_blanks(&res, form, 1);
	else if (form->flg->zero == 1)
		apply_zero(&res, form);
	else
		apply_blanks(&res, form, 0);
	ft_putstr(res);
	prec = ft_strlen(res);
	free(res);
	(void)form;
	return (prec);
}
