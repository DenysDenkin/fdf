/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:34:32 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/18 19:39:20 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		apply_precision(char **res, t_form *form)
{
	int		len;
	char	*temp;
	char	*ttmp;

	len = ((*res)[0] == '-') ? ft_strlen(*res) - 1 : ft_strlen(*res);
	if (len < form->prec)
	{
		temp = (char *)malloc(sizeof(char) * (form->prec - len + 1));
		temp[form->prec - len] = 0;
		ft_memset(temp, '0', form->prec - len);
		if (*res[0] == '-')
		{
			*res[0] = '0';
			temp[0] = '-';
		}
		ttmp = *res;
		*res = ft_strjoin(temp, *res);
		ft_strdel2(&ttmp, &temp);
	}
	else if (form->prec == 0 && ft_strcmp(*res, "0") == 0)
	{
		free(*res);
		*res = ft_strdup("");
	}
}

void		apply_precisions(char **res, t_form *form)
{
	char	*tmp1;

	if (ft_strlen(*res) > (size_t)form->prec)
	{
		tmp1 = (char *)malloc(sizeof(char) * (form->prec + 1));
		ft_strncpy(tmp1, *res, form->prec);
		tmp1[form->prec] = 0;
		free(*res);
		*res = tmp1;
	}
}
