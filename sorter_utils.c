/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:49:18 by fseles            #+#    #+#             */
/*   Updated: 2023/10/25 16:49:20 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//push lowest element to b, 
//sort three elements in a, push lowest from b to a again
void	group_commands(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b, 2);
	three_element_sorter(list_a);
	push(list_b, list_a, 1);
}

//push lowest element to b, 
//sort four elements in a, push lowest from b to a again
void	group_commands2(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b, 2);
	four_element_sorter(list_a, list_b);
	push(list_b, list_a, 1);
}

//return position of relative value 0;
// 0 1 2 3-> return 1
// 1 9 0 4.. -> return 3
int	get_position_of_lowest(t_list *list_a)
{
	int		i;
	t_list	*element;
	t_data	*p;

	element = list_a;
	i = 1;
	while (element != NULL)
	{
		p = (t_data *)element->content;
		if (p->relative_value == 0)
			return (i);
		i++;
		element = element->next;
	}
	return (i);
}
