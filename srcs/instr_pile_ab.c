/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_pile_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:59:37 by nabboufe          #+#    #+#             */
/*   Updated: 2019/07/01 16:16:29 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

int		ft_ss(t_numbers *list, int truth)
{
	ft_sa(list, 0);
	ft_sb(list, 0);
	if (truth)
		ft_printf("ss\n");
	return (1);
}

int		ft_rr(t_numbers *list, int truth)
{
	ft_ra(list, 0);
	ft_rb(list, 0);
	if (truth)
		ft_printf("rr\n");
	return (1);
}

int		ft_rrr(t_numbers *list, int truth)
{
	ft_rra(list, 0);
	ft_rrb(list, 0);
	if (truth)
		ft_printf("rrr\n");
	return (1);
}
