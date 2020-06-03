/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:39:00 by nabboufe          #+#    #+#             */
/*   Updated: 2019/07/01 16:16:34 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	n_rrb(t_numbers *list, int count)
{
	while (count--)
		ft_rrb(list, 1);
}

void	n_rra(t_numbers *list, int count)
{
	while (count--)
		ft_rra(list, 1);
}

int		n_pa(t_numbers *list, int count)
{
	int		i;

	i = 0;
	while (i++ < count)
		ft_pa(list, 1);
	return (count);
}

int		n_pb(t_numbers *list, int count)
{
	int		i;

	i = 0;
	while (i++ < count)
		ft_pb(list, 1);
	return (1);
}
