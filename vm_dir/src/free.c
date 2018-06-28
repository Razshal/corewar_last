/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:14:11 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/28 16:15:17 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		free_visu(t_visu *visu, t_vm *vm)
{
	ft_memdel((void**)&visu);
	vm->visu ? endwin() : 0;
	vm->dump != -1 ? mem_dump(vm->map) : 0;
	return (1);
}

t_champ	*rec_free_champs(t_champ *champs)
{
	if (!champs)
		return (NULL);
	if (champs->next)
		rec_free_champs(champs->next);
	ft_memdel((void**)&champs->code);
	ft_memdel((void**)&champs);
	return (NULL);
}

void	rec_free_processes(t_process *processes)
{
	if (!processes)
		return ;
	if (processes->next)
		rec_free_processes(processes->next);
	ft_memdel((void**)&processes);
}

t_vm	*free_vm(t_vm *vm)
{
	if (!vm)
		return (NULL);
	if (vm->map)
		ft_memdel((void**)&vm->map);
	if (vm->champ)
		rec_free_champs(vm->champ);
	if (vm->processes)
		rec_free_processes(vm->processes);
	if (vm->colors_map)
		ft_memdel((void**)&vm->colors_map);
	ft_memdel((void**)&vm);
	return (0);
}
