/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexs_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:21:34 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/12 14:54:01 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	apply_sharp(char **res, t_form *form)
{
	char	*tmp;
	char	*tmp2;

	tmp = *res;
	if ((*res)[0] == '0' && (*res)[1] == '0' &&\
			ft_strlen(*res) >= (size_t)form->prec + 2)
		(*res)[1] = 'x';
	else if ((*res)[0] == '0' && (*res)[1] != '0')
	{
		(*res)[0] = 'x';
		tmp2 = ft_strdup("0");
		*res = ft_strjoin(tmp2, *res);
		ft_strdel2(&tmp, &tmp2);
	}
	else
	{
		tmp2 = ft_strdup("0X");
		*res = ft_strjoin(tmp2, *res);
		ft_strdel2(&tmp, &tmp2);
	}
}

int			hex_handler(va_list *va, t_form *form)
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
	if (form->flg->sharp == 1 && i != 0)
		apply_sharp(&res, form);
	if (form->flg->minus == 1)
		apply_blanks(&res, form, 1);
	apply_blanks(&res, form, 0);
	if (form->conv == 'x')
		ft_tolowers(res);
	else
		ft_touppers(res);
	ft_putstr(res);
	ret = ft_strlen(res);
	free(res);
	return (ret);
}
