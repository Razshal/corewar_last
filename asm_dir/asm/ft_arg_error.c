/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line_in_bloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:57:47 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/28 11:58:34 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_arg_error(int nb_param, char type, int instr)
{
	char *res;
	char *ins;

	if (nb_param == -1 && type == '0' && instr == -1)
	{
		ft_putstr("Wrong number of arguments");
		exit(0);
	}
	if (type == '1')
		res = "direct";
	else if (type == '2')
		res = "indirect";
	else
		res = "register";
	ins = g_op_tab[instr].str;
	ft_putstr("Invalid parameter ");
	ft_putnbr(nb_param - 1);
	ft_putstr(" type ");
	ft_putstr(res);
	ft_putstr(" for instruction ");
	ft_putendl(ins);
	exit(0);
}
