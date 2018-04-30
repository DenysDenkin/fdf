/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:01:16 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/17 19:03:47 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hasdollar(const char *format)
{
	char	*temp;

	temp = (char *)format;
	while (ft_isdigit(*temp))
		temp++;
	if (*temp == '$')
		return (1);
	else
		return (0);
}
