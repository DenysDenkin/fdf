/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:19:54 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/11 18:09:23 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	apply_sharp(char **res)
{
	char	*tmp;
	char	*tmp2;

	if ((*res)[0] != '0')
	{
		tmp = *res;
		tmp2 = ft_strdup("0");
		*res = ft_strjoin(tmp2, *res);
		ft_strdel2(&tmp, &tmp2);
	}
}

int			octal_handler(va_list *va, t_form *form)
{
	uintmax_t		i;
	char			*res;
	int				ret;

	i = va_arg(*va, uintmax_t);
	if (i == 0 && form->prec == 0)
		res = ft_strdup("");
	else
		res = unum_handler(form, &i);
	apply_precision(&res, form);
	if (form->flg->zero == 1 && form->prec == -1 && form->flg->minus == 0)
		apply_zero(&res, form);
	if (form->flg->sharp == 1)
		apply_sharp(&res);
	if (form->flg->minus == 1)
		apply_blanks(&res, form, 1);
	apply_blanks(&res, form, 0);
	ft_putstr(res);
	ret = ft_strlen(res);
	free(res);
	return (ret);
}
