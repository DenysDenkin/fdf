/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:23:11 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/11 21:04:57 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			perc_handler(va_list *va, t_form *form)
{
	char	*res;
	int		ret;

	(void)va;
	res = ft_strdup("%");
	if (form->flg->minus == 0 && form->flg->zero == 1)
		apply_zero(&res, form);
	else
		apply_blanks(&res, form, form->flg->minus);
	ft_putstr(res);
	ret = ft_strlen(res);
	ft_strdel(&res);
	return (ret);
}
