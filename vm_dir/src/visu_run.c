/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:24:18 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/28 15:17:11 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	user_key2(t_visu *visu)
{
	nodelay(stdscr, TRUE);
	if (visu->ch == 114)
		visu->slow = 300000;
	if (visu->ch == 116)
		visu->slow = 0;
	if (visu->ch == 49)
	{
		while (visu->ch != 49)
			visu->ch = getch();
	}
}

void	user_key(WINDOW *score, t_visu *visu)
{
	nodelay(stdscr, TRUE);
	visu->ch = getch();
	if (visu->ch == 100)
	{
		if (visu->slow > 0)
			visu->slow = visu->slow - 3000;
	}
	if (visu->ch == 115)
		visu->slow = visu->slow + 3000;
	if (visu->ch == 3)
	{
		clear();
		exit(0);
	}
	if (visu->ch == 32)
	{
		mvwprintw(score, 1, 5, "***PAUSED***");
		wrefresh(score);
		nodelay(stdscr, FALSE);
		while (visu->ch != 112)
			visu->ch = getch();
	}
	user_key2(visu);
}

void	take_in_pc(t_visu *visu, t_vm vm)
{
	while (visu->ind < vm.processes_nbr)
	{
		visu->pc[visu->ind] = vm.processes->pc;
		vm.processes = vm.processes->next;
		visu->ind++;
	}
}

void	visu_run(t_vm vm, WINDOW *win, t_visu *visu, WINDOW *score)
{
	visu->pos = 0;
	visu->ind = 0;
	init_pairy_print_header(score, win);
	if (!(visu->pc = (int*)ft_memalloc(sizeof(int) * (vm.processes_nbr))))
		exit(0);
	take_in_pc(visu, vm);
	user_key(score, visu);
	wattron(score, COLOR_PAIR(7));
	box(score, ACS_VLINE, ACS_HLINE);
	print_score(visu, score, vm, win);
	wattron(score, COLOR_PAIR(7));
	box(score, ACS_VLINE, ACS_HLINE);
	wattroff(score, COLOR_PAIR(7));
	wrefresh(win);
	wrefresh(score);
	if (!visu->start)
		nodelay(stdscr, FALSE);
	visu->ch = getch();
	usleep(visu->slow);
	ft_memdel((void**)&visu->pc);
}
