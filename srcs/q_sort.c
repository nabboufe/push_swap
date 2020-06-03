/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:25:41 by nabboufe          #+#    #+#             */
/*   Updated: 2019/07/01 16:16:41 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_end(t_numbers *list, int min, int max)
{
	if (min == list->list_0[0])
		ft_ra(list, 1) && ft_sa(list, 1) && ft_rra(list, 1);
	else if (min == list->list_0[1])
		max == list->list_0[0] ? ft_sa(list, 1) && ft_ra(list, 1)
			&& ft_sa(list, 1) && ft_rra(list, 1) : ft_sa(list, 1);
	else if (max == list->list_0[1])
		ft_ra(list, 1) && ft_sa(list, 1)
			&& ft_rra(list, 1) && ft_sa(list, 1);
	else
		ft_sa(list, 1) && ft_ra(list, 1) && ft_sa(list, 1)
			&& ft_rra(list, 1) && ft_sa(list, 1);
}

void	ft_start(t_numbers *list, int min, int max)
{
	if (min == list->list_0[0])
		ft_sa(list, 1) && ft_ra(list, 1);
	else if (min == list->list_0[1])
		max == list->list_0[0] ? ft_ra(list, 1) : ft_sa(list, 1);
	else if (max == list->list_0[1])
		ft_rra(list, 1);
	else
		ft_ra(list, 1) && ft_sa(list, 1);
}

void	solve_it(t_numbers *list, int truth)
{
	int		min;
	int		max;

	min = v_min(list->list_0, 3);
	max = v_max(list->list_0, 3);
	if (truth == 1)
		ft_start(list, min, max);
	else
		ft_end(list, min, max);
}

int		sq_sort(t_numbers *list, int size)
{
	if (size < 3 || isrev_sort(list, size))
	{
		if (!isrev_sort(list, size))
			ft_sb(list, 1);
		n_pa(list, size);
		return (1);
	}
	p_median_1(list, size);
	fq_sort(list, size / 2 + size % 2);
	sq_sort(list, size / 2);
	return (0);
}

int		fq_sort(t_numbers *list, int size)
{
	if (size < 4 || is_sorted(list, size))
	{
		if (!is_sorted(list, size))
		{
			if (list->elements_0 == 3 && size == 3)
				solve_it(list, 1);
			else if (size == 3)
				solve_it(list, 0);
			if (size == 2)
				ft_sa(list, 1);
		}
		return (1);
	}
	p_median_0(list, size);
	fq_sort(list, ((size / 2) + (size % 2)));
	sq_sort(list, size / 2);
	return (0);
}
