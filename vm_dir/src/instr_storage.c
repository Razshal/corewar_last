/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_storage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:10:07 by mfonteni          #+#    #+#             */
/*   Updated: 2018/06/28 15:14:23 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int	st(t_instr instr)
{
	get_params(&instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[0].value))
		return (free_params(instr, 0));
	if (instr.params[1].type == T_REG && instr.params[1].value <= REG_NUMBER
	&& valid_reg(instr.params[1].value - 1))
	{
		instr.params[1].value--;
		instr.process->reg[instr.params[1].value] =
		instr.process->reg[instr.params[0].value];
	}
	else if (instr.params[1].type == T_IND)
		int_to_bytes(instr.process->reg[instr.params[0].value],
		get_address(instr.process->pc + (instr.params[1].value % IDX_MOD)),
		instr.vm->map, instr);
	else
		return (free_params(instr, 0));
	return (free_params(instr, 1));
}

int	sti(t_instr instr)
{
	get_params(&instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[0].value)
	|| !convert_params_start(&instr, 1, 3))
		return (free_params(instr, 0));
	int_to_bytes(instr.process->reg[instr.params[0].value],
	get_address(instr.process->pc +
	((instr.params[1].value + instr.params[2].value) % IDX_MOD)),
	instr.vm->map, instr);
	return (free_params(instr, 1));
}
