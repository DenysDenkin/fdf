/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_minusblank.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:30:15 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/12 14:51:08 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		apply_blanks(char **res, t_form *form, int minus)
{
	int		len;
	char	*temp;
	char	*ttmp;

	len = ft_strlen(*res);
	if (len < form->min_w)
	{
		temp = (char *)malloc(sizeof(char) * (form->min_w - len + 1));
		temp[form->min_w - len] = 0;
		ft_memset(temp, ' ', form->min_w - len);
		ttmp = *res;
		*res = (minus == 0) ? ft_strjoin(temp, *res) : ft_strjoin(*res, temp);
		ft_strdel2(&ttmp, &temp);
	}
}

void		apply_blanksw(char **res, t_form *form, int minus)
{
	int		len;
	char	*temp;
	char	*ttmp;

	len = (form->prec != -1) ? ft_min(form->prec, ft_strlen(*res)) \
			: ft_strlen(*res);
	if (len < form->min_w)
	{
		temp = (char *)malloc(sizeof(char) * (form->min_w - len + 1));
		temp[form->min_w - len] = 0;
		ft_memset(temp, ' ', form->min_w - len);
		ttmp = *res;
		*res = (minus == 0) ? ft_strjoin(temp, *res) : ft_strjoin(*res, temp);
		ft_strdel2(&ttmp, &temp);
	}
}
