/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:08:16 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/13 20:26:48 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <time.h>

int		date_handler(va_list *va, t_form *form)
{
	time_t		t;
	struct tm	tm;

	(void)form;
	(void)va;
	t = time(NULL);
	tm = *localtime(&t);
	return (ft_printf("%.4d-%.2d-%.2d", tm.tm_year + 1900,\
				tm.tm_mon + 1, tm.tm_mday));
}
