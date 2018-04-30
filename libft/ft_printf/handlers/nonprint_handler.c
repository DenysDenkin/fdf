/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonprint_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:04:59 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/19 16:30:37 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	unprint_size(unsigned char *str)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] <= 31 || str[i] >= 127)
			res += 3;
		else
			res++;
		i++;
	}
	return (res);
}

static void	unprint_to_print(char *dst, unsigned char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] <= 31 || src[i] >= 127)
		{
			dst[j++] = '\\';
			dst[j++] = (src[i] / 16 <= 9) ? src[i] / 16 + 48 : src[i] / 16 + 87;
			dst[j++] = (src[i] % 16 <= 9) ? src[i] % 16 + 48 : src[i] % 16 + 87;
		}
		else
			dst[j++] = src[i];
		i++;
	}
}

int			nonprint_handler(va_list *va, t_form *form)
{
	int				i;
	unsigned char	*str;
	char			*res;
	int				true_size;

	i = 0;
	str = va_arg(*va, unsigned char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	true_size = unprint_size(str);
	res = (char *)malloc(sizeof(char) * (true_size + 1));
	res[true_size] = 0;
	unprint_to_print(res, str);
	write(1, res, true_size);
	(void)form;
	ft_strdel(&res);
	return (true_size);
}
