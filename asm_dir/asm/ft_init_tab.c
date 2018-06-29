/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:57:47 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/29 12:31:10 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**  1 = DIRECT
**  2 = INDIRECT
**  3 = REGISTRE
*/

char	**ft_init_tab(void)
{
	char **tab;

	tab = (char**)ft_memalloc(sizeof(char*) * 16 + 1);
	tab[0] = ft_strdup("1;");
	tab[1] = ft_strdup("1|2,3;");
	tab[2] = ft_strdup("3,2|3;");
	tab[3] = ft_strdup("3,3,3;");
	tab[4] = ft_strdup("3,3,3;");
	tab[5] = ft_strdup("3|1|2,3|2|1,3;");
	tab[6] = ft_strdup("3|2|1,3|2|1,3;");
	tab[7] = ft_strdup("3|2|1,3|2|1,3;");
	tab[8] = ft_strdup("1;");
	tab[9] = ft_strdup("3|1|2,1|3,3;");
	tab[10] = ft_strdup("3,3|1|2,1|3;");
	tab[11] = ft_strdup("1;");
	tab[12] = ft_strdup("1|2,3;");
	tab[13] = ft_strdup("3|1|2,1|3,3;");
	tab[14] = ft_strdup("1;");
	tab[15] = ft_strdup("3;");
	return (tab);
}
