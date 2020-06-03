/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:53:48 by nabboufe          #+#    #+#             */
/*   Updated: 2019/07/01 16:16:39 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	t_numbers		*list;

	if (argc < 2 || !(list = (t_numbers *)malloc(sizeof(t_numbers))))
		return (0);
	insert_elem(list, &argv[1], argc - 1);
	fq_sort(list, list->elements_0);
	free(list->list_0);
	free(list->list_1);
	free(list);
}
