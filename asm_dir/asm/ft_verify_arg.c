/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:57:47 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/29 14:05:04 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
 **	1 = DIRECT
 **	2 = INDIRECT
 **	3 = REGISTRE
 */

int		ft_take_nb_arg(t_chain block)
{
	int	nb_arg;

	nb_arg = 0;
	while (block.category && !ft_strequ(block.category, "ENDL"))
	{
		block = *block.next;
		nb_arg++;
	}
	nb_arg--;
	return (nb_arg);
}

void	ft_init_type(t_chain *block)
{
	while (block)
	{
		if (ft_strequ(block->category, "ARG"))
		{
			if (block->content[0] == 'r')
				block->type = '3';
			else if (block->content[0] == DIRECT_CHAR)
				block->type = '1';
			else if (ft_isdigit(block->content[0]) ||
					block->content[0] == LABEL_CHAR || block->content[0] == '-')
				block->type = '2';
		}
		block = block->next;
	}
}

int		ft_search(char type, int nb_arg, int nb_tab, char **tab)
{
	int	sep;
	int	i;

	i = 0;
	sep = 1;
	while (sep < nb_arg)
	{
		if (tab[nb_tab][i] == ',')
			sep++;
		i++;
		if (tab[nb_tab][i] == ';')
			return (0);
	}
	while (tab[nb_tab][i] != ';' && tab[nb_tab][i] != ',')
	{
		if (type == tab[nb_tab][i]){
			return(1);}
		i++;
	}
	return (0);
}

void	ft_check_nb_arg(t_arg *arg, t_chain *block)
{
	if (ft_strequ(block->category, "INSTRUCTION"))
	{
		arg->nb_arg = ft_take_nb_arg(*block);
		if (arg->nb_arg != g_op_tab[block->nb_op_tab].nb_args)
			ft_arg_error(-1, '0', -1);
		arg->op_c_nb = block->nb_op_tab;
		block = block->next;
		while (ft_strequ(block->category, "ARG"))
		{
			if (!ft_search(block->type, arg->pro, arg->op_c_nb, arg->tab))
				ft_arg_error(arg->pro, block->type, arg->op_c_nb);
			block = block->next;
			arg->pro++;
		}
		arg->pro = 1;
	}
}

void	ft_verify_arg(t_chain *block)
{
	t_arg	*arg;
	int 	i;

	i = 0;
	arg = ft_memalloc(sizeof(t_arg));
	arg->pro = 1;
	arg->tab = ft_init_tab();
	ft_init_type(block);
	while (block)
	{
		ft_check_nb_arg(arg, block);
		block = block->next;
	}
	while (i < 16)
		ft_strdel(&arg->tab[i++]);
	ft_memdel((void**)&arg->tab);
	ft_memdel((void**)&arg);
}
