/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:53:02 by alecott           #+#    #+#             */
/*   Updated: 2018/06/29 14:21:13 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../includes/op.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_chain
{
	char			*content;
	char			*category;
	char			type;
	int				line;
	int				index;
	int				arg_type;
	int				size;
	unsigned int	nb_col;
	unsigned int	nb_lines;
	int				nb_op_tab;
	struct s_chain	*next;
}					t_chain;

typedef struct		s_main
{
	int				fd;
	char			*str;
	char			*getall;
	int				nb;
}					t_main;

typedef struct		s_arg
{
	char			**tab;
	int				nb_arg;
	int				pro;
	int				op_c_nb;
}					t_arg;

int					main(int argc, char **argv);
void				ft_pass_comment(char *str, int *i);
t_chain				*ft_parsing(char *str, t_header *header, char *str2);
void				ft_is_an_error(char *str, int i);
void				ft_verify_arg(t_chain *block, char *str);
t_chain				*ft_get_in_chain(char *str, int j);
int					ft_complete_content(t_chain *block, char *str, int *i);
int					ft_checkbegin(char *str, int *i);
int					ft_put_line_in_block(t_chain *b, int *i, char *str);
void				ft_verify_label(char *str, t_chain *block);
void				ft_arg_error(int nb_arg, char type, int nb_tab);
t_op				*ft_search_op(char *str);
void				ft_asm(char *str, t_chain *block, t_header *header);
void				ft_arg_type(t_chain *block);
void				ft_putint_bin(int n, int fd);
void				ft_putshort_bin(short n, int fd);
void				ft_putstr_bin(char *str, int fd);
void				ft_ocp(t_chain block, int fd);
void				ft_pass_space(char *str, int *j);
int					ft_is_lib(char *str, int i);
void				ft_write_cor(int fd, t_header *header, t_chain block);
void				ft_nbr_link(t_chain *block);
char				*ft_find_label(t_chain block, t_chain start);
char				**ft_init_tab(void);

#endif
