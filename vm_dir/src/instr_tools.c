/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:36:15 by mfonteni          #+#    #+#             */
/*   Updated: 2018/06/29 14:46:07 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		live(t_instr instr)
{
	t_champ *thischamp;

	instr.process->alive = 1;
	instr.vm->lives++;
	if (!instr.vm || !instr.vm->champ
	|| !(thischamp = get_champ_by_num(instr.vm->champ,
	byte_to_int(instr.vm->map, instr.process->pc + 1, 4))))
	{
		if (instr.vm && instr.vm->champ && !instr.vm->visu)
			ft_printf("Une instruction live en faveur du joueur %d a echoue\n",
				byte_to_int(instr.vm->map, instr.process->pc + 1, 4));
		return (decal_pc(instr, 5, 0));
	}
	thischamp->lives++;
	instr.vm->last = thischamp;
	!instr.vm->visu ?
	ft_printf("Un processus dit que le joueur %d(%s) est en vie\n",
	thischamp->id, thischamp->name) : 0;
	return (decal_pc(instr, 5, 1));
}

int		zjmp(t_instr instr)
{
	if (instr.process->carry == 0)
		return (decal_pc(instr, 3, 0));
	instr.process->pc = get_address(
		instr.process->pc + byte_to_int(
			instr.vm->map, instr.process->pc + 1, 2) % IDX_MOD);
	instr.process->cycles_left = -1;
	return (decal_pc(instr, 0, 1));
}

int		aff(t_instr instr)
{
	t_champ *champ;

	get_params(&instr);
	if (!compare_params(instr.params, instr.opcode)
		|| !valid_reg(--instr.params[0].value))
		return (free_params(instr, 0));
	if ((champ = get_champ_by_num(instr.vm->champ,
		instr.process->reg[0])))
		ft_printf("Champion %s says : %c\n", champ->name,
			instr.process->reg[instr.params[0].value]);
	else
		ft_printf("%c\n", instr.params[0].value);
	return (free_params(instr, 1));
}

int		decal_pc(t_instr instr, int decal, int ret)
{
	instr.process->pc = (instr.process->pc + decal) % MEM_SIZE;
	instr.process->cycles_left = -1;
	return (ret);
}

t_champ	*get_champ_by_num(t_champ *list, int num)
{
	t_champ *current;

	if (!list)
		return (NULL);
	current = list;
	while (current)
	{
		if (current->id == num)
			return (current);
		current = current->next;
	}
	return (NULL);
}
