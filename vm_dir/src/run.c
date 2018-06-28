/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:22:38 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/28 16:41:49 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

static void	init_instr_tab(t_vm *vm)
{
	vm->instr_tab[0] = &live;
	vm->instr_tab[1] = &ld;
	vm->instr_tab[2] = &st;
	vm->instr_tab[3] = &add;
	vm->instr_tab[4] = &sub;
	vm->instr_tab[5] = &and;
	vm->instr_tab[6] = &or;
	vm->instr_tab[7] = &xor;
	vm->instr_tab[8] = &zjmp;
	vm->instr_tab[9] = &ldi;
	vm->instr_tab[10] = &sti;
	vm->instr_tab[11] = &core_fork;
	vm->instr_tab[12] = &lld;
	vm->instr_tab[13] = &lldi;
	vm->instr_tab[14] = &core_lfork;
	vm->instr_tab[15] = &aff;
}

static int	exec_process(t_process *process, t_vm *vm)
{
	unsigned char	opc;

	if (!process)
		return (0);
	while (process)
	{
		if (process->cycles_left > 1)
			process->cycles_left--;
		else
		{
			opc = vm->map[process->pc % MEM_SIZE];
			if (opc < 1 || opc > 16)
				decal_pc((instr_params(vm, process, opc)), 1, 0);
			else if (process->cycles_left == -1)
				process->cycles_left = g_op_tab[opc - 1].nb_cycles - 1;
			else
				vm->instr_tab[opc - 1](instr_params(vm, process, opc));
		}
		process = process->next;
	}
	return (1);
}

int			mem_dump(unsigned char *map)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x", map[i++]);
		if (!(i % 32) && i != 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
	}
	return (1);
}

static void	check_vm(t_vm *vm, int *check)
{
	t_champ *ch;

	ch = vm->champ;
	check_process(vm);
	if (*check == MAX_CHECKS || vm->lives >= NBR_LIVE)
	{
		*check = 0;
		vm->ctd -= CYCLE_DELTA;
	}
	vm->cycle = 0;
	vm->lives = 0;
	*check += 1;
	while (ch)
	{
		ch->lives = 0;
		ch = ch->next;
	}
}

int			run(t_vm *vm)
{
	int		check;
	t_visu	*visu;

	check = 0;
	if (vm->visu && !(visu = inti_visu()))
		return (0);
	init_instr_tab(vm);
	vm->ctd = CYCLE_TO_DIE;
	while (vm->processes_nbr && vm->ctd > 0)
	{
		if (vm->cycle == vm->ctd)
			check_vm(vm, &check);
		exec_process(vm->processes, vm);
		vm->visu ? visu_run(*vm, visu->win, visu, visu->score) : 0;
		if (vm->tt_cycle == vm->dump)
			return (vm->visu ? free_visu(visu, vm) : mem_dump(vm->map));
		vm->cycle++;
		vm->tt_cycle++;
		vm->visu ? visu->start = 1 : 0;
	}
	return (vm->visu ? free_visu(visu, vm) : 1);
}
