/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:35:47 by nabboufe          #+#    #+#             */
/*   Updated: 2019/07/01 16:16:20 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		isrev_sort(t_numbers *list, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (i + j < (*list).elements_1)
		{
			if ((*list).list_1[i] < (*list).list_1[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		is_sorted(t_numbers *list, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (i + j < (*list).elements_0)
		{
			if ((*list).list_0[i] > (*list).list_0[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
