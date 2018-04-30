/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:08:00 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/18 19:40:39 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*dec_handler(t_form *form, intmax_t *num)
{
	if (form->conv == 'd' || form->conv == 'i')
	{
		if (form->lmod == NULL)
			return (ft_lltoa((int)*num));
		if (ft_strcmp(form->lmod, "l") == 0)
			return (ft_lltoa((long)*num));
		if (ft_strcmp(form->lmod, "ll") == 0)
			return (ft_lltoa((long long)*num));
		if (ft_strcmp(form->lmod, "hh") == 0)
			return (ft_lltoa((char)*num));
		if (ft_strcmp(form->lmod, "h") == 0)
			return (ft_lltoa((short)*num));
		if (ft_strcmp(form->lmod, "j") == 0)
			return (ft_lltoa(*num));
		if (ft_strcmp(form->lmod, "z") == 0 && sizeof(size_t) == sizeof(long))
			return (ft_lltoa((long)*num));
		if (ft_strcmp(form->lmod, "z") == 0 && sizeof(size_t)\
				== sizeof(long long))
			return (ft_lltoa((long long)*num));
	}
	if (form->conv == 'D')
		return (ft_lltoa((long)*num));
	return (NULL);
}

static char		*u_handler(t_form *form, uintmax_t *num, int base)
{
	if (form->conv == 'u' || form->conv == 'o' || form->conv == 'x' \
			|| form->conv == 'X' || form->conv == 'b')
	{
		if (form->lmod == NULL)
			return (ft_ulltoa_base((unsigned int)*num, base));
		if (ft_strcmp(form->lmod, "hh") == 0)
			return (ft_ulltoa_base((unsigned char)*num, base));
		if (ft_strcmp(form->lmod, "h") == 0)
			return (ft_ulltoa_base((unsigned short)*num, base));
		if (ft_strcmp(form->lmod, "l") == 0)
			return (ft_ulltoa_base((unsigned long)*num, base));
		if (ft_strcmp(form->lmod, "ll") == 0)
			return (ft_ulltoa_base((unsigned long long)*num, base));
		if (ft_strcmp(form->lmod, "j") == 0)
			return (ft_ulltoa_base((uintmax_t)*num, base));
		if (ft_strcmp(form->lmod, "z") == 0)
			return (ft_ulltoa_base((size_t)*num, base));
	}
	if (form->conv == 'U' || form->conv == 'O')
		return (ft_ulltoa_base((unsigned long)*num, base));
	return (NULL);
}

char			*unum_handler(t_form *form, uintmax_t *num)
{
	if (form->conv == 'u' || form->conv == 'U')
		return (u_handler(form, num, 10));
	if (form->conv == 'X' || form->conv == 'x')
		return (u_handler(form, num, 16));
	if (form->conv == 'o' || form->conv == 'O')
		return (u_handler(form, num, 8));
	if (form->conv == 'b')
		return (u_handler(form, num, 2));
	return (NULL);
}
