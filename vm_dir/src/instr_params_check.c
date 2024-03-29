/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_params_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by mfonteni          #+#    #+#             */
/*   Updated: 2018/06/29 15:16:23 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		compare_params(t_param *params, int opcode)
{
	int i;

	i = -1;
	if (!params || --opcode < 0 || opcode > 17)
		return (0);
	while (++i < 3)
	{
		if (g_op_tab[opcode].args[i]
			&& !((params[i].type & g_op_tab[opcode].args[i])))
			return (0);
		else if (!g_op_tab[opcode].args[i])
			params[i].type = 0;
	}
	return (1);
}

int		convert_params(t_instr *instr, int limit)
{
	return (convert_params_start(instr, 0, limit));
}

int		convert_params_start(t_instr *instr, int start, int limit)
{
	int i;

	i = start - 1;
	while (++i < limit)
	{
		if (instr->params[i].type == T_REG)
		{
			if (!valid_reg(--instr->params[i].value))
				return (0);
			instr->params[i].value = instr->process->reg[
				instr->params[i].value];
		}
		else if (instr->params[i].type == T_IND)
			instr->params[i].value = byte_to_int(
				instr->vm->map, get_address((instr->process->pc
					+ (instr->params[i].value % IDX_MOD))), DIR_SIZE);
	}
	return (1);
}

int		convert_params_unrestrained(t_instr *instr, int limit)
{
	int i;

	i = -1;
	while (++i < limit)
	{
		if (instr->params[i].type == T_REG)
		{
			if (!valid_reg(--instr->params[i].value))
				return (0);
			instr->params[i].value = instr->process->reg[
				instr->params[i].value];
		}
		else if (instr->params[i].type == T_IND)
			instr->params[i].value = byte_to_int(
				instr->vm->map, get_address((instr->process->pc
					+ instr->params[i].value)), DIR_SIZE);
	}
	return (1);
}

int		valid_reg(int reg)
{
	if (reg < REG_NUMBER && reg >= 0)
		return (1);
	return (0);
}
