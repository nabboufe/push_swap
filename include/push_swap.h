/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:44:38 by nabboufe          #+#    #+#             */
/*   Updated: 2019/07/01 16:41:17 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct			s_numbers
{
	int					*list_0;
	int					*list_1;
	int					elements_0;
	int					elements_1;
}						t_numbers;

void					l_print(t_numbers *list);

void					ft_swap(int *i, int *j);
int						ft_sa(t_numbers *list, int truth);
int						ft_sb(t_numbers *list, int truth);
int						ft_ss(t_numbers *list, int truth);
int						ft_ra(t_numbers *list, int truth);
int						ft_rb(t_numbers *list, int truth);
int						ft_rr(t_numbers *list, int truth);
int						ft_rra(t_numbers *list, int truth);
int						ft_rrb(t_numbers *list, int truth);
int						ft_rrr(t_numbers *list, int truth);
int						ft_pa(t_numbers *list, int truth);
int						ft_pb(t_numbers *list, int truth);

void					n_rrb(t_numbers *list, int count);
void					n_rra(t_numbers *list, int count);
int						n_pa(t_numbers *list, int count);
int						n_pb(t_numbers *list, int count);

int						isrev_sort(t_numbers *list, int size);
int						is_sorted(t_numbers *list, int size);

void					insert_elem(t_numbers *list, char **argv, int argc);
int						check_doublons(int *list, int size);
int						check_nb(char **argv, int argc);
void					quit(t_numbers *list, int truth);
long					ft_ltoa(char *str);
size_t					ft_strtab(const char **str);
int						free_all(char **str, int truth);

int						v_min(int *tab, int size);
int						v_max(int *tab, int size);
double					find_pivot(int *tab, int size, double out);
void					p_median_1(t_numbers *list, int size);
void					p_median_0(t_numbers *list, int size);

void					f_case(t_numbers *list);
void					solve_it(t_numbers *list, int truth);
int						sq_sort(t_numbers *list, int size);
int						fq_sort(t_numbers *list, int size);

#endif
