/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:22:38 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/28 15:10:39 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void		unset_pro_lives(t_process *pro)
{
	while (pro)
	{
		pro->alive = 0;
		pro = pro->next;
	}
}

void		check_process(t_vm *vm)
{
	t_process	*pro;
	t_process	*del;

	pro = vm->processes;
	while (pro->next)
		if (pro->next->alive == 0)
		{
			del = pro->next;
			pro->next = pro->next->next;
			ft_memdel((void**)&del);
			vm->processes_nbr -= 1;
		}
		else if (pro->next)
			pro = pro->next;
	if (vm->processes->alive == 0)
	{
		del = vm->processes;
		vm->processes = vm->processes->next;
		ft_memdel((void**)&del);
		vm->processes_nbr -= 1;
	}
	unset_pro_lives(vm->processes);
}

int			add_process(t_vm *vm, int pc, int id)
{
	t_process	*pro;
	t_process	*new;

	pro = vm->processes;
	if (!(new = (t_process*)ft_memalloc(sizeof(t_process))))
		return (error_mall(0));
	new->alive = 1;
	new->pc = pc;
	new->carry = 0;
	new->cycles_left = -1;
	bzero((void *)new->reg, sizeof(new->reg));
	new->reg[0] = id;
	new->next = pro;
	vm->processes_nbr += 1;
	vm->processes = new;
	return (1);
}
