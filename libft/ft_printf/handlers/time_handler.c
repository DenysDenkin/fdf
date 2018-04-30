/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:22:50 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/13 20:26:30 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <time.h>

int		time_handler(va_list *va, t_form *form)
{
	time_t		t;
	struct tm	tm;

	(void)form;
	(void)va;
	t = time(NULL);
	tm = *localtime(&t);
	return (ft_printf("%.2d:%.2d:%.2d", tm.tm_hour, tm.tm_min, tm.tm_sec));
}
