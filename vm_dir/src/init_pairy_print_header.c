/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:24:18 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/28 15:09:35 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	print_header(WINDOW *win)
{
	int		x_offset;

	x_offset = 79;
	wattron(win, COLOR_PAIR(1));
	mvwprintw(win, 1, x_offset, HEADER_LINE_1);
	mvwprintw(win, 2, x_offset, HEADER_LINE_2);
	wattroff(win, COLOR_PAIR(1));
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 3, x_offset, HEADER_LINE_3);
	mvwprintw(win, 4, x_offset, HEADER_LINE_4);
	wattroff(win, COLOR_PAIR(2));
	wattron(win, COLOR_PAIR(3));
	mvwprintw(win, 5, x_offset, HEADER_LINE_5);
	wattroff(win, COLOR_PAIR(3));
	wrefresh(win);
}

void	init_pairy_print_header(WINDOW *score, WINDOW *win)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_GREEN);
	init_pair(9, COLOR_BLACK, COLOR_RED);
	init_pair(10, COLOR_BLACK, COLOR_BLUE);
	init_pair(11, COLOR_BLACK, COLOR_YELLOW);
	init_pair(12, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(13, COLOR_BLACK, COLOR_CYAN);
	init_pair(14, COLOR_BLACK, COLOR_WHITE);
	wattron(score, COLOR_PAIR(7));
	mvwprintw(score, 45, 5, "Press 'Enter' to start");
	mvwprintw(score, 47, 5, "Press 'Space' to pause");
	mvwprintw(score, 49, 5, "Press 'P' to resume");
	mvwprintw(score, 51, 5, "Press 'S' to add delay");
	mvwprintw(score, 53, 5, "Press 'D' to reduce delay");
	mvwprintw(score, 55, 5, "Press 'T' to delete delay");
	mvwprintw(score, 57, 5, "Press 'R' to go step by step");
	wattroff(score, COLOR_PAIR(7));
	print_header(win);
}
