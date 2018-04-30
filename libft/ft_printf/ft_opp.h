/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:34:07 by ddenkin           #+#    #+#             */
/*   Updated: 2017/12/18 16:05:57 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPP_H
# define FT_OPP_H

t_opp g_opptab[] =
{
	{"s", &string_handler},
	{"S", &wstring_handler},
	{"p", &pointer_handler},
	{"d", &int_handler},
	{"D", &int_handler},
	{"i", &int_handler},
	{"n", &n_handler},
	{"o", &octal_handler},
	{"O", &octal_handler},
	{"u", &unsigned_handler},
	{"U", &unsigned_handler},
	{"x", &hex_handler},
	{"X", &hex_handler},
	{"c", &char_handler},
	{"C", &wchar_handler},
	{"%", &perc_handler},
	{"e", &e_handler},
	{"E", &e_handler},
	{"f", &f_handler},
	{"F", &f_handler},
	{"g", &g_handler},
	{"G", &g_handler},
	{"a", &a_handler},
	{"A", &a_handler},
	{"b", &binary_handler},
	{"r", &nonprint_handler},
	{"k", &date_handler},
	{"t", &time_handler},
	{"m", &mass_handler},
	{NULL, NULL}
};
#endif
