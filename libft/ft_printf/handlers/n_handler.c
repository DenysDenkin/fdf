/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:11:37 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/08 18:54:03 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	n_handler_h(t_form *form, intmax_t *num)
{
	if (form->conv == 'n')
	{
		if (form->lmod == NULL)
			*num = (int)form->res;
		else if (ft_strcmp(form->lmod, "hh") == 0)
			*num = (signed char)form->res;
		else if (ft_strcmp(form->lmod, "h") == 0)
			*num = (short)form->res;
		else if (ft_strcmp(form->lmod, "l") == 0)
			*num = (long)form->res;
		else if (ft_strcmp(form->lmod, "ll") == 0)
			*num = (long long)form->res;
		else if (ft_strcmp(form->lmod, "j") == 0)
			*num = (intmax_t)form->res;
		else if (ft_strcmp(form->lmod, "z") == 0 &&\
				sizeof(long) == sizeof(size_t))
			*num = (long)form->res;
		else if (ft_strcmp(form->lmod, "z") == 0 &&\
				sizeof(long long) == sizeof(size_t))
			*num = (long long)form->res;
	}
}

int			n_handler(va_list *va, t_form *form)
{
	intmax_t	*num;

	num = va_arg(*va, intmax_t*);
	n_handler_h(form, num);
	return (0);
}
