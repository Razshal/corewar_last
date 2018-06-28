/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:05:09 by mfonteni          #+#    #+#             */
/*   Updated: 2018/06/28 15:16:06 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int	add(t_instr instr)
{
	get_params(&instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[0].value)
	|| !valid_reg(--instr.params[1].value)
	|| !valid_reg(--instr.params[2].value))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value] =
	instr.process->reg[instr.params[0].value]
	+ instr.process->reg[instr.params[1].value];
	instr.process->carry = instr.process->reg[instr.params[2].value] == 0;
	return (free_params(instr, 1));
}

int	sub(t_instr instr)
{
	get_params(&instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[0].value)
	|| !valid_reg(--instr.params[1].value)
	|| !valid_reg(--instr.params[2].value))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value] =
	instr.process->reg[instr.params[0].value]
	- instr.process->reg[instr.params[1].value];
	instr.process->carry = instr.process->reg[instr.params[2].value] == 0;
	return (free_params(instr, 1));
}

int	and(t_instr instr)
{
	get_params(&instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[2].value) || !convert_params(&instr, 2))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value] =
	instr.params[0].value & instr.params[1].value;
	instr.process->carry = instr.process->reg[instr.params[2].value] == 0;
	return (free_params(instr, 1));
}

int	or(t_instr instr)
{
	get_params(&instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[2].value) || !convert_params(&instr, 2))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value] =
	instr.params[0].value | instr.params[1].value;
	instr.process->carry = instr.process->reg[instr.params[2].value] == 0;
	return (free_params(instr, 1));
}

int	xor(t_instr instr)
{
	get_params(&instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[2].value) || !convert_params(&instr, 2))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value] =
	instr.params[0].value ^ instr.params[1].value;
	instr.process->carry = instr.process->reg[instr.params[2].value] == 0;
	return (free_params(instr, 1));
}
