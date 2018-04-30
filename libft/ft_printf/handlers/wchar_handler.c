/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:53:37 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/19 16:27:50 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			wchar_handler(va_list *va, t_form *form)
{
	int		ch;

	ch = va_arg(*va, int);
	(void)form;
	if (MB_CUR_MAX == 1)
		return (ft_putchar((char)ch));
	else
		return (ft_putchar(ch));
}
