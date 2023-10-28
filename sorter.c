/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:36:46 by fseles            #+#    #+#             */
/*   Updated: 2023/10/25 15:36:48 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_element_sorter(t_list **list_a)
{
	if (is_list_sorted(*list_a) == 1)
		return ;
	else
		swap(list_a, 1);
}

//hard coded three element most efficent sorter
void	three_element_sorter(t_list **list_a)
{
	t_data	*p1;
	t_data	*p2;

	set_relative_value(*list_a);
	if (is_list_sorted(*list_a) == 1)
		return ;
	p1 = (t_data *)(*list_a)->content;
	p2 = (t_data *)(*list_a)->next->content;
	if (p1->relative_value == 0 && p2->relative_value == 2)
	{
		swap(list_a, 1);
		rotate(list_a, 1);
	}
	if (p1->relative_value == 1 && p2->relative_value == 0)
		swap(list_a, 1);
	if (p1->relative_value == 1 && p2->relative_value == 2)
		reverse_rotate(list_a, 1);
	if (p1->relative_value == 2 && p2->relative_value == 0)
		rotate(list_a, 1);
	if (p1->relative_value == 2 && p2->relative_value == 1)
	{
		swap(list_a, 1);
		reverse_rotate(list_a, 1);
	}
}

//hard coded four element sorter
void	four_element_sorter(t_list **list_a, t_list **list_b)
{
	int	position_of_lowest;

	set_relative_value(*list_a);
	position_of_lowest = get_position_of_lowest(*list_a);
	if (position_of_lowest == 2)
		swap(list_a, 1);
	if (position_of_lowest == 3)
	{
		rotate(list_a, 1);
		swap(list_a, 1);
	}
	if (position_of_lowest == 4)
		reverse_rotate(list_a, 1);
	if (is_list_sorted(*list_a) == 1)
		return ;
	group_commands(list_a, list_b);
}

//hard coded five element sorter
void	five_element_sorter(t_list **list_a, t_list **list_b)
{
	int	position_of_lowest;

	set_relative_value(*list_a);
	position_of_lowest = get_position_of_lowest(*list_a);
	if (position_of_lowest == 2)
		swap(list_a, 1);
	if (position_of_lowest == 3)
	{
		rotate(list_a, 1);
		swap(list_a, 1);
	}
	if (position_of_lowest == 4)
	{
		reverse_rotate(list_a, 1);
		reverse_rotate(list_a, 1);
	}
	if (position_of_lowest == 5)
		reverse_rotate(list_a, 1);
	if (is_list_sorted(*list_a) == 0)
		group_commands2(list_a, list_b);
}

//sort list a depeneding on how many elements there are till 5 is hardcoded
// more than five use redix sort
void	sorter(t_list **list_a, t_list **list_b)
{
	int	elements;

	elements = ft_lstsize(*list_a);
	if (elements == 1)
		return ;
	else if (elements == 2)
		two_element_sorter(list_a);
	else if (elements == 3)
		three_element_sorter(list_a);
	else if (elements == 4)
		four_element_sorter(list_a, list_b);
	else if (elements == 5)
		five_element_sorter(list_a, list_b);
	else
	{
		set_relative_value(*list_a);
		radix_sort(list_a, list_b);
	}
}
