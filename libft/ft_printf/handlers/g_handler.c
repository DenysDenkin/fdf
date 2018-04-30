/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:12:25 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/18 19:45:06 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		trimzeros(char *str, int exp)
{
	int		end;

	if (exp <= 0)
		return ;
	end = ft_strlen(str);
	if (end > 0)
		end--;
	while (exp-- >= 0 && str[end] == '0')
		str[end--] = 0;
	if (str[end] == '.')
		str[end] = 0;
}

char		*choose_side(int *size, t_form *form, int *mant, double d)
{
	int		prec;
	char	*res;
	int		exp;

	exp = ft_countexp(d);
	if (exp < -4 || exp > form->prec)
	{
		*size = 0;
		*mant = 1;
		prec = form->prec - *mant;
		if (prec < 0)
			prec = 0;
		res = ft_detoa(d, prec);
	}
	else
	{
		*size = 1;
		prec = form->prec - *mant;
		if (prec < 0)
			prec = 0;
		res = ft_dtoa(d, prec);
		(form->flg->app == 1) ? apply_app(&res) : 1;
	}
	return (res);
}

int			g_handler(va_list *va, t_form *form)
{
	int		mant;
	int		size;
	double	d;
	char	*res;

	if (form->prec == 0)
		form->prec = 1;
	else if (form->prec == -1)
		form->prec = 6;
	d = double_handler(va, form);
	mant = ((int)d % 10 == 0) ? ft_countmant(d) - 1 : ft_countmant(d);
	res = choose_side(&size, form, &mant, d);
	trimzeros(res, form->prec - mant);
	if (form->flg->minus == 1)
		apply_blanks(&res, form, 1);
	else if (form->flg->zero == 1)
		apply_zero(&res, form);
	else
		apply_blanks(&res, form, 0);
	if (form->conv == 'G' && size == 0)
		ft_touppers(res);
	ft_putstr(res);
	size = ft_strlen(res);
	free(res);
	return (size);
}
