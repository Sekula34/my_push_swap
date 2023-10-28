/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:21:58 by fseles            #+#    #+#             */
/*   Updated: 2023/10/25 20:22:00 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//addig node to the end of list with original and relative value -1;
//return 0 on succes -1 if something goes wrong
static int	add_node(char *ascii_value, t_list **head_a)
{
	int		i_value;
	t_data	*p_data;
	t_list	*node;

	i_value = ft_atoi(ascii_value);
	p_data = malloc(sizeof(t_data));
	if (p_data == NULL)
		return (-1);
	p_data->original_value = i_value;
	p_data->relative_value = -1;
	node = ft_lstnew(p_data);
	if (node == NULL)
		return (free(p_data), -1);
	ft_lstadd_back(head_a, node);
	return (1);
}

//filler if arguments are like ./push swap "45 67 89 -3"
static int	two_argument_filler(t_list **head_a, char *string)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(string, ' ');
	if (arr == NULL)
		return (-1);
	while (arr[i] != NULL)
	{
		if (add_node(arr[i], head_a) == -1)
			return (free_arr(arr), -1);
		i++;
	}
	free_arr(arr);
	return (1);
}

//filler if arguments are like ./push swap 34 56 78 -3
static int	more_arguments_filler(t_list **head_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (add_node(argv[i], head_a) == -1)
			return (-1);
		i++;
	}
	return (1);
}

//initialize list dependig of arguments format "56 78" or 56 78
//return -1 if something goes terribly wrong, 1 is ok
int	initialize_list(int argc, char **argv, t_list **head_a)
{
	if (argc == 2)
	{
		if (two_argument_filler(head_a, argv[1]) == -1)
			return (-1);
	}
	else
	{
		if (more_arguments_filler(head_a, argc, argv) == -1)
			return (-1);
	}
	return (1);
}
