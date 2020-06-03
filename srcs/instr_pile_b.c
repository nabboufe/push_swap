/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_pile_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:54:56 by nabboufe          #+#    #+#             */
/*   Updated: 2019/07/01 16:16:31 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_sb(t_numbers *list, int truth)
{
	if ((*list).elements_1 < 2)
		return (1);
	ft_swap(&(*list).list_1[0], &(*list).list_1[1]);
	if (truth)
		ft_printf("sb\n");
	return (1);
}

int		ft_rb(t_numbers *list, int truth)
{
	int		n;

	n = 0;
	while (n + 1 < list->elements_1)
	{
		ft_swap(&list->list_1[n], &list->list_1[n + 1]);
		n++;
	}
	if (truth)
		ft_printf("rb\n");
	return (1);
}

int		ft_rrb(t_numbers *list, int truth)
{
	int		n;

	n = list->elements_1 - 1;
	while (n > 0)
	{
		ft_swap(&list->list_1[n], &list->list_1[n - 1]);
		n--;
	}
	if (truth)
		ft_printf("rrb\n");
	return (1);
}

int		ft_pb(t_numbers *list, int truth)
{
	int		n;
	int		tmp;

	n = list->elements_1;
	if (list->elements_0 == 0)
		return (1);
	tmp = list->list_0[0];
	while (n > 0)
	{
		ft_swap(&list->list_1[n], &list->list_1[n - 1]);
		n--;
	}
	list->list_1[0] = tmp;
	n = 0;
	while (n < list->elements_0)
	{
		ft_swap(&list->list_0[n], &list->list_0[n + 1]);
		n++;
	}
	list->elements_1 += 1;
	list->elements_0 -= 1;
	if (truth)
		ft_printf("pb\n");
	return (1);
}
