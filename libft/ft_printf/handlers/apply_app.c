/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_app.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:44:32 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/17 20:29:51 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <locale.h>

static void	apply_app_h(char **res, char *separator, int len)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if ((tmp = ft_strchr(*res, '.')) != NULL)
	{
		len -= ft_strlen(tmp);
	}
	while ((len - 3) > 0)
	{
		tmp = ft_strdup((*res) + len - 3);
		tmp2 = *res;
		(*res)[len - 3] = 0;
		*res = ft_strjoin(*res, separator);
		tmp3 = *res;
		*res = ft_strjoin(*res, tmp);
		ft_strdel3(&tmp, &tmp2, &tmp3);
		len -= 3;
	}
}

void		apply_app(char **res)
{
	struct lconv	*l;
	char			*separator;
	int				len;

	l = localeconv();
	separator = l->thousands_sep;
	len = ft_strlen(*res);
	apply_app_h(res, separator, len);
}
