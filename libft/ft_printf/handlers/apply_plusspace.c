/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_plusspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:27:14 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/12 14:40:51 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	apply_plusspace(char **res, t_form *form, char symb)
{
	char	*tmp;
	char	*tmp2;

	if (((*res)[0] == '0' || (*res)[0] == ' ') && ft_isdigit((*res)[1]) &&\
			ft_strlen(*res) > (size_t)form->prec && form->prec != -1)
		(*res)[0] = symb;
	else if (((*res)[0] == '0' || (*res)[0] == ' ') && ft_isdigit((*res)[1]) \
			&& ft_strlen(*res) >= (size_t)form->min_w && form->min_w != 0 \
			&& form->prec == -1)
		(*res)[0] = symb;
	else if ((*res)[0] != '-')
	{
		tmp = *res;
		tmp2 = ft_strndup(&symb, 1);
		*res = ft_strjoin(tmp2, *res);
		ft_strdel2(&tmp, &tmp2);
	}
}
