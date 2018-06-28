/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:40:13 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/27 15:33:46 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

static void			winner(t_champ *ch)
{
	if (ch)
		ft_printf("Le joueur %d(%s) a gagne !\n", ch->id, ch->name);
	else
		ft_printf("Une hecatombe ... Personne ne gagne :(\n");
}

int					main(int argc, char **argv)
{
	t_vm	*vm;

	if (argc < 2)
		return (usage(1));
	if (!check_inputs())
		return (1);
	if (!(vm = init_vm(argc, argv)))
		return (1);
	if (run(vm))
		winner(vm->last);
	free_vm(vm);
	return (0);
}
