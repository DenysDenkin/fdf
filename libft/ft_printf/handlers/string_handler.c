/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:17:09 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/11 20:54:18 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			string_handler(va_list *va, t_form *form)
{
	int		i;
	char	*tmp1;

	if (form->lmod && ft_strcmp(form->lmod, "l") == 0)
		return (wstring_handler(va, form));
	tmp1 = va_arg(*va, char *);
	if (tmp1 == NULL && form->prec == -1)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (tmp1 != NULL)
		tmp1 = ft_strdup(tmp1);
	else
		tmp1 = ft_strdup("");
	apply_precisions(&tmp1, form);
	if (form->flg->minus == 1)
		apply_blanks(&tmp1, form, 1);
	else if (form->flg->zero == 1)
		apply_zero(&tmp1, form);
	apply_blanks(&tmp1, form, 0);
	ft_putstr(tmp1);
	i = ft_strlen(tmp1);
	ft_strdel(&tmp1);
	return (i);
}
