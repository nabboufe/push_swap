/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:02:47 by nabboufe          #+#    #+#             */
/*   Updated: 2019/07/14 12:11:32 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quit(t_numbers *list, int truth)
{
	int		i;

	i = 0;
	ft_printf("Error\n");
	if (truth)
	{
		if (truth > 1)
			free(list->list_0);
		if (truth > 2)
			free(list->list_1);
	}
	free(list);
	exit(1);
}

int		check_doublons(int *list, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (i + j < size)
		{
			if (list[i] == list[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_nb(char **argv, int argc)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& argv[i][j + 1])
			j++;
		while (argv[i][j])
		{
			if ((!ft_isdigit((int)argv[i][j]) && argv[i][j] != ' ')
					|| (argc == 1 && argv[i][j] == ' '))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	insert_nelem(t_numbers *list, char *argv)
{
	char	**str;
	long	result;
	int		nb;

	str = ft_strsplit(argv, ' ');
	nb = ft_strtab((const char **)str);
	if (!check_nb(str, nb))
		free_all(str, 1);
	if (!(list->list_0 = (int *)malloc(sizeof(int) * nb)))
		quit(list, 0);
	if (!(list->list_1 = (int *)malloc(sizeof(int) * nb)))
		quit(list, 2);
	list->elements_1 = 0;
	list->elements_0 = nb;
	while (nb--)
	{
		result = ft_ltoa(str[nb]);
		if ((result > 2147483647 || result < -2147483648) && free_all(str, 1))
			quit(list, 3);
		list->list_0[nb] = (int)result;
		list->list_1[nb] = 0;
	}
	free_all(str, 0);
	if (!check_doublons(list->list_0, list->elements_0))
		quit(list, 3);
}

void	insert_elem(t_numbers *list, char **argv, int argc)
{
	int		i;
	long	result;

	i = 0;
	if (argc == 1)
		return (insert_nelem(list, argv[0]));
	if (!(list->list_0 = (int *)malloc(sizeof(int) * argc)))
		quit(list, 0);
	if (!(list->list_1 = (int *)malloc(sizeof(int) * argc)))
		quit(list, 2);
	if (!check_nb(argv, argc))
		quit(list, 3);
	list->elements_1 = 0;
	list->elements_0 = argc;
	while (argc)
	{
		result = ft_ltoa(argv[argc - 1]);
		if (result > 2147483647 || result < -2147483648)
			quit(list, 3);
		list->list_0[argc - 1] = (int)result;
		list->list_1[argc - 1] = 0;
		argc--;
	}
	if (!check_doublons(list->list_0, list->elements_0))
		quit(list, 3);
}
