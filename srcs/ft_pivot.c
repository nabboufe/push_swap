/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:21:14 by nabboufe          #+#    #+#             */
/*   Updated: 2019/07/01 16:16:22 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		v_min(int *tab, int size)
{
	int		v_min;
	int		i;

	i = 0;
	v_min = tab[0];
	while (size--)
	{
		if (tab[i] < v_min)
			v_min = tab[i];
		i++;
	}
	return (v_min);
}

int		v_max(int *tab, int size)
{
	int		v_max;
	int		i;

	i = 0;
	v_max = tab[0];
	while (size--)
	{
		if (tab[i] > v_max)
			v_max = tab[i];
		i++;
	}
	return (v_max);
}

double	find_pivot(int *tab, int size, double out)
{
	int		tmp;
	int		i;
	int		left;
	int		right;

	i = 0;
	left = 0;
	right = 0;
	tmp = size;
	while (size)
	{
		if (tab[i] != out)
			tab[i] > out ? right++ : left++;
		i++;
		size--;
		if (size == 0 && right != left)
		{
			out += (right > left) ? 0.5 : -0.5;
			i = 0;
			size = tmp;
			left = 0;
			right = 0;
		}
	}
	return (out);
}

void	p_median_1(t_numbers *list, int size)
{
	int			limit;
	double		pivot;
	int			count;

	limit = 0;
	count = 0;
	pivot = find_pivot(list->list_1, size,
		(v_min(list->list_1, size) + v_max(list->list_1, size) / 2));
	while (count < size / 2 + size % 2)
	{
		if (list->list_1[0] < pivot)
		{
			limit++;
			ft_rb(list, 1);
		}
		else
		{
			ft_pa(list, 1);
			count++;
		}
	}
	if (list->elements_1 > size / 2)
		n_rrb(list, limit);
}

void	p_median_0(t_numbers *list, int size)
{
	int			limit;
	double		pivot;
	int			count;

	limit = 0;
	count = 0;
	pivot = find_pivot(list->list_0, size,
		(v_min(list->list_0, size) + v_max(list->list_0, size) / 2));
	while (count < (size / 2))
	{
		if (list->list_0[0] >= pivot)
		{
			limit++;
			ft_ra(list, 1);
		}
		else
		{
			ft_pb(list, 1);
			count++;
		}
	}
	if (list->elements_0 > ((size / 2) + (size % 2)))
		n_rra(list, limit);
}
