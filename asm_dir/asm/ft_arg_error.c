/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:57:47 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/29 11:56:30 by abouvero         ###   ########.fr       */
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
	ft_putstr_fd("Invalid parameter ", 2);
	ft_putnbr_fd(nb_param - 1, 2);
	ft_putstr_fd(" type ", 2);
	ft_putstr_fd(res, 2);
	ft_putstr_fd(" for instruction ", 2);
	ft_putendl_fd(ins, 2);
	exit(0);
}
