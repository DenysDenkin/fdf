/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:33:58 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/08 17:02:51 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	apply_zero(char **res, t_form *form)
{
	int		len;
	char	*temp;
	char	*ttmp;

	len = ft_strlen(*res);
	if (len < form->min_w)
	{
		temp = (char *)malloc(sizeof(char) * (form->min_w - len + 1));
		temp[form->min_w - len] = 0;
		ft_memset(temp, '0', form->min_w - len);
		if (*res[0] == '-')
		{
			*res[0] = '0';
			temp[0] = '-';
		}
		ttmp = *res;
		*res = ft_strjoin(temp, *res);
		ft_strdel(&ttmp);
		ft_strdel(&temp);
	}
}
