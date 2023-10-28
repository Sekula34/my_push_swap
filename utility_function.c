/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:41:30 by fseles            #+#    #+#             */
/*   Updated: 2023/10/25 20:41:32 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

//return 1 if list is sorted, 0 if not
int	is_list_sorted(t_list *head)
{
	int		noe;
	int		correct_position;
	t_data	*p;

	noe = ft_lstsize(head);
	if (noe <= 1)
		return (1);
	correct_position = 0;
	while (head != NULL)
	{
		p = (t_data *)(head->content);
		if (p->relative_value != correct_position)
			return (0);
		correct_position++;
		head = head->next;
	}
	return (1);
}
