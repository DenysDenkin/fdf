/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mass_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:06:19 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/18 16:19:43 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		mass_handler(va_list *va, t_form *form)
{
	char	**arr;
	int		i;
	int		res;

	arr = va_arg(*va, char **);
	i = 0;
	res = 0;
	while (arr[i] != NULL && (i < form->prec || form->prec == -1))
		res += (form->flg->minus == 1) ? ft_printf("%-*s\n", form->min_w,\
				arr[i++]) : ft_printf("%*s\n", form->min_w, arr[i++]);
	return (res);
}
