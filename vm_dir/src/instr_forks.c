/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:10:23 by mfonteni          #+#    #+#             */
/*   Updated: 2018/06/28 15:16:21 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int	core_fork(t_instr instr)
{
	int i;

	i = -1;
	add_process(instr.vm, get_address(instr.process->pc +
	(byte_to_int(instr.vm->map, instr.process->pc + 1, 2) % IDX_MOD)),
	instr.process->reg[0]);
	instr.vm->processes->carry = instr.process->carry;
	instr.vm->processes->alive = instr.process->alive;
	instr.vm->processes->color = instr.process->color;
	while (++i < REG_NUMBER)
		instr.vm->processes->reg[i] = instr.process->reg[i];
	return (decal_pc(instr, 3, 1));
}

int	core_lfork(t_instr instr)
{
	int i;

	i = -1;
	add_process(instr.vm, get_address(instr.process->pc +
	byte_to_int(instr.vm->map, instr.process->pc + 1, 2)),
	instr.process->reg[0]);
	instr.vm->processes->carry = instr.process->carry;
	instr.vm->processes->alive = instr.process->alive;
	instr.vm->processes->color = instr.process->color;
	while (++i < REG_NUMBER)
		instr.vm->processes->reg[i] = instr.process->reg[i];
	return (decal_pc(instr, 3, 1));
}
