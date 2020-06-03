/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:25:52 by nabboufe          #+#    #+#             */
/*   Updated: 2019/07/01 16:16:37 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	l_print(t_numbers *list)
{
	int		i;

	i = 0;
	while (i < list->elements_1)
	{
		ft_printf("\t\t%d\n", list->list_1[i]);
		i++;
	}
	i = 0;
	while (i < list->elements_0)
	{
		ft_printf("%d\n", list->list_0[i]);
		i++;
	}
}
