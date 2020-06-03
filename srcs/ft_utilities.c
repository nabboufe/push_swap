/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:53:49 by nabboufe          #+#    #+#             */
/*   Updated: 2019/07/01 16:16:24 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		check_l(char *str)
{
	int		i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (ft_strlen(&str[i]) > 11)
		return (0);
	return (1);
}

long	ft_ltoa(char *str)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (!check_l(str))
		return (2147483648);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i = 1;
	}
	while (str[i])
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return ((result * sign));
}

size_t	ft_strtab(const char **str)
{
	size_t i;

	i = 0;
	if (str == NULL || (!(str)))
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

int		free_all(char **str, int truth)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	if (truth)
	{
		ft_printf("Error\n");
		exit(0);
	}
	return (1);
}
