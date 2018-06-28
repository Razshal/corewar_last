/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:49:14 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/28 15:11:20 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	print_pc(t_visu *visu, t_vm vm)
{
	visu->ind = 0;
	while (visu->ind < vm.processes_nbr)
	{
		visu->pcx = 5 + (visu->pc[visu->ind] * 3);
		visu->pcy = 7;
		if ((visu->pc[visu->ind] >= 64) && visu->pc[visu->ind] != 0)
		{
			visu->pcx = 5 + ((visu->pc[visu->ind] % 64) * 3);
			visu->pcy = 7 + (visu->pc[visu->ind] / 64);
		}
		attron(COLOR_PAIR(vm.colors_map[visu->pc[visu->ind]] + 7));
		mvprintw(visu->pcy, visu->pcx, "%.2x", vm.map[visu->pc[visu->ind]]);
		attroff(COLOR_PAIR(vm.colors_map[visu->pc[visu->ind]] + 7));
		visu->ind++;
	}
}

void	print_map_and_pc(t_visu *visu, WINDOW *win, t_vm vm)
{
	int x;
	int y;

	x = 5;
	y = 7;
	while (visu->pos < MEM_SIZE)
	{
		wattron(win, COLOR_PAIR(vm.colors_map[visu->pos]));
		mvwprintw(win, y, x, "%.2x", vm.map[visu->pos++]);
		x += 2;
		if (!(visu->pos % 64) && visu->pos != 0)
		{
			mvwprintw(win, y, x, "\n");
			x = 5;
			y++;
		}
		else
		{
			mvwprintw(win, y, x, " ");
			x++;
		}
		wattroff(win, COLOR_PAIR(vm.colors_map[visu->pos - 1]));
	}
	print_pc(visu, vm);
}

void	print_infos(t_visu *visu, t_vm vm, WINDOW *score)
{
	mvwprintw(score, 5, 5, "Cycle number :     %d\n", vm.tt_cycle);
	mvwprintw(score, 7, 5, "Cycle to die :     %d\n", vm.ctd);
	mvwprintw(score, 9, 5, "Processus number : %d\n", vm.processes_nbr);
	mvwprintw(score, 11, 5, "Delay :            %d\n", visu->slow);
}

void	print_score(t_visu *visu, WINDOW *score, t_vm vm, WINDOW *win)
{
	int k;

	k = 2;
	if (!visu->start)
		mvwprintw(score, 1, 5, "***PAUSED***");
	else
		mvwprintw(score, 1, 5, "***RUNNING***");
	print_infos(visu, vm, score);
	visu->ind = 1;
	while (vm.champ)
	{
		wattron(score, COLOR_PAIR(7));
		mvwprintw(score, 13 + k, 5, "Player %d name: ", vm.champ->id);
		mvwprintw(score, 15 + k, 5, "Current lives: ");
		wattron(score, COLOR_PAIR(visu->ind));
		mvwprintw(score, 13 + k, 29, "%s", vm.champ->name);
		mvwprintw(score, 15 + k, 29, "%-6d", vm.champ->lives);
		k += 8;
		vm.champ = vm.champ->next;
		visu->ind++;
	}
	wattroff(score, COLOR_PAIR(7));
	print_map_and_pc(visu, win, vm);
}
