/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:51:36 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/17 16:46:49 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	trimzeros(char **str)
{
	char	*exp;
	char	*tmp1;
	int		end;

	end = ft_strlen(*str);
	if (end > 0)
		end--;
	while (end >= 0 && (*str)[end] != 'p')
		end--;
	if ((*str)[end - 1] != '0')
		return ;
	exp = ft_strdup((*str) + end);
	end--;
	while ((*str)[end] == '0')
		(*str)[end--] = 0;
	if ((*str)[end] == '.')
		(*str)[end] = 0;
	tmp1 = (*str);
	(*str) = ft_strjoin(*str, exp);
	ft_strdel2(&tmp1, &exp);
}

int			a_handler(va_list *va, t_form *form)
{
	double	d;
	int		prec;
	char	*res;

	d = double_handler(va, form);
	prec = (form->prec == -1) ? 19 : form->prec;
	res = ft_detoa_base(d, prec, 16);
	if (form->flg->minus == 1)
		apply_blanks(&res, form, 1);
	else if (form->flg->zero == 1)
		apply_zero(&res, form);
	else
		apply_blanks(&res, form, 0);
	trimzeros(&res);
	if (form->conv == 'A')
		ft_touppers(res);
	ft_putstr(res);
	prec = ft_strlen(res);
	free(res);
	return (prec);
}
