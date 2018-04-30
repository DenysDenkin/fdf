/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:30:15 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/17 16:08:01 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

double	double_handler(va_list *va, t_form *form)
{
	double d;

	if (form->lmod && form->lmod[0] == 'L')
		d = va_arg(*va, long double);
	else
		d = va_arg(*va, double);
	return (d);
}
