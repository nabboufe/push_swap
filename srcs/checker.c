/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:52:47 by nabboufe          #+#    #+#             */
/*   Updated: 2019/10/21 20:28:40 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		check_instr(char *instr, t_numbers *list)
{
	if (ft_strcmp("sa\n", instr) == 0)
		return (ft_sa(list, 0));
	if (ft_strcmp("sb\n", instr) == 0)
		return (ft_sb(list, 0));
	if (ft_strcmp("ss\n", instr) == 0)
		return (ft_ss(list, 0));
	if (ft_strcmp("pa\n", instr) == 0)
		return (ft_pa(list, 0));
	if (ft_strcmp("pb\n", instr) == 0)
		return (ft_pb(list, 0));
	if (ft_strcmp("ra\n", instr) == 0)
		return (ft_ra(list, 0));
	if (ft_strcmp("rb\n", instr) == 0)
		return (ft_rb(list, 0));
	if (ft_strcmp("rr\n", instr) == 0)
		return (ft_rr(list, 0));
	if (ft_strcmp("rra\n", instr) == 0)
		return (ft_rra(list, 0));
	if (ft_strcmp("rrb\n", instr) == 0)
		return (ft_rrb(list, 0));
	if (ft_strcmp("rrr\n", instr) == 0)
		return (ft_rrr(list, 0));
	return (0);
}

int		read_it(char instr[5], const int fd)
{
	int		i;

	i = 0;
	ft_printf("?? | fd == %d\n", fd);
	while (i < 4 && read(fd, &instr[i], 1) &&
			((fd == 0 && instr[i] != '\n') || fd != 0))
		i++;
	if (i == 0)
		return (0);
	if (fd == 0 && instr[i] != '\n')
		return (-1);
	instr[i + 1] = '\0';
	return (1);
}

void	read_instr(t_numbers *list, const int fd)
{
	char	instr[5];
	int		truth;
	int		ret;

	truth = 1;
	while ((ret = read_it(instr, fd)))
	{
		if (truth)
			truth = check_instr((char *)instr, list);
		ft_bzero(instr, sizeof(instr));
	}
	if (truth == 0 || ret == -1)
		write(2, "Error\n", 6);
	else if (is_sorted(list, list->elements_0) && !list->elements_1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	get_numbers(const int fd, t_numbers *list)
{
	char	number[5];
	char	*f_str;

	f_str = NULL;
	(void)list;
	while ((read_it(number, fd)))
	{
		f_str = ft_strjoin(f_str, number, 1);
		ft_bzero(number, 5);
	}
	ft_printf("f_str ==\n%s\n", f_str);
}

int		ft_check(int argc, char **argv, t_numbers *list)
{
	int		fd;

	fd = -1;
	if (argc == 3 && argv[1][0] == '-' && argv[1][1] == 'f' && argv[1][2] == '\0'
			&& (fd = open(argv[2], O_RDONLY) != -1))
		get_numbers(fd, list);
	else if (argc == 2)
		return (0);
	else
		write(2, "Error\n", 6);
	if (list->list_0 != NULL)
		free(list->list_0);
	if (list->list_1)
		free(list->list_1);
	free(list);
	return (1);
}

int		main(int argc, char **argv)
{
	t_numbers		*list;

	list = NULL;
	if (!(list = (t_numbers *)malloc(sizeof(t_numbers))))
		return (0);
	list->list_0 = NULL;
	list->list_1 = NULL;
	if (ft_check(argc, argv, list))
		return (0);
	insert_elem(list, &argv[1], argc - 1);
	read_instr(list, 0);
	free(list->list_0);
	free(list->list_1);
	free(list);
	return (0);
}
