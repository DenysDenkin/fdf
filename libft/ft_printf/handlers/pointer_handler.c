/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:18:36 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/12 14:44:09 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	apply_sharp(char **res, t_form *form)
{
	char	*tmp;
	char	*tmp2;

	tmp = *res;
	if ((*res)[0] == '0' && (*res)[1] == '0' && ft_strlen(*res) >= \
			(size_t)form->prec + 2)
	{
		(*res)[1] = 'x';
	}
	else if ((*res)[0] == '0' && (*res)[1] != '0' && (*res)[1] != 0)
	{
		(*res)[0] = 'x';
		tmp2 = ft_strdup("0");
		*res = ft_strjoin(tmp2, *res);
		ft_strdel2(&tmp, &tmp2);
	}
	else
	{
		tmp2 = ft_strdup("0x");
		*res = ft_strjoin(tmp2, *res);
		ft_strdel2(&tmp, &tmp2);
	}
	(void)form;
}

int			pointer_handler(va_list *va, t_form *form)
{
	size_t	ptr;
	char	*res;
	int		i;

	i = 0;
	ptr = va_arg(*va, size_t);
	if (ptr == 0)
		res = ft_strdup("0");
	else
		res = ft_ulltoa_base(ptr, 16);
	apply_precision(&res, form);
	if (form->flg->zero == 1 && form->prec == -1 && form->flg->minus == 0)
		apply_zero(&res, form);
	apply_sharp(&res, form);
	if (form->flg->minus == 1)
		apply_blanks(&res, form, 1);
	else
		apply_blanks(&res, form, 0);
	i = ft_strlen(res);
	ft_putstr(res);
	free(res);
	return (i);
}
