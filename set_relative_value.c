/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_relative_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:34:53 by fseles            #+#    #+#             */
/*   Updated: 2023/10/25 20:34:55 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//will look at number from node and increase i 
//for every number that is bigger in list
static int	get_relative_value(t_list *head, int value_to_compare)
{
	int		i;
	t_data	*p;

	i = 0;
	while (head != NULL)
	{
		p = (t_data *)(head->content);
		if (value_to_compare > (p->original_value))
			i++;
		head = head->next;
	}
	return (i);
}

//set relative value to each node of list
// 4 8 3 will be 1 2 0
void	set_relative_value(t_list *head)
{
	t_data	*p;
	int		value_to_compare;
	t_list	*loop;

	loop = head;
	while (loop != NULL)
	{
		p = (t_data *)(loop->content);
		value_to_compare = p->original_value;
		p->relative_value = get_relative_value(head, value_to_compare);
		loop = loop->next;
	}
}
