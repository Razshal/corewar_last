/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_an_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:07:56 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/29 11:58:30 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_is_an_error(char *str, int i)
{
	int j;
	int	col;
	int	nb_line;

	j = 0;
	col = 1;
	nb_line = 1;
	while (j != i)
	{
		if (str[j] == '\n')
		{
			nb_line++;
			col = 1;
		}
		j++;
		col++;
	}
	col--;
	ft_putstr_fd("Error line ", 2);
	ft_putnbr_fd(nb_line, 2);
	ft_putstr_fd(" column ", 2);
	ft_putnbr_fd(col, 2);
	ft_putchar_fd('\n', 2);
	exit(0);
}
