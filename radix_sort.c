/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:17:48 by fseles            #+#    #+#             */
/*   Updated: 2023/10/25 12:17:50 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//loop throgh every element in list a, and apply action
//if relative value of lista >> shift & 1 == 1 rotate a
//else push to b
//at the end push every element from b to a with pa
//s_v stands for shifting value norm!!
static void	loop_every_element_a(t_list **list_a, t_list **list_b, int s_v)
{
	int		number_of_elements;
	int		i;
	int		value;
	t_data	*p;
	t_list	*element;

	i = 0;
	number_of_elements = ft_lstsize(*list_a);
	while (i < number_of_elements)
	{
		element = *list_a;
		p = (t_data *)element->content;
		value = p->relative_value;
		if (((value >> s_v) & 1) == 1)
			rotate(list_a, 1);
		else
			push(list_a, list_b, 2);
		i++;
	}
	while (*list_b != NULL)
	{
		push(list_b, list_a, 1);
	}
}

//calculate how many bits number have 2 have 2 (10) 10 have 4 (1010)
static int	get_max_bits(int value)
{
	int	i;

	i = 0;
	while ((value >> i) != 0)
	{
		i++;
	}
	return (i);
}

//radix sort if leftmost bit is 0 goes in list b for every element
// push everything to list a, repeaft for next bit till rightmost
void	radix_sort(t_list **a_list, t_list **b_list)
{
	int		max_relative;
	int		max_bits;
	int		i;

	max_relative = ft_lstsize(*a_list) - 1;
	max_bits = get_max_bits(max_relative);
	i = 0;
	while (i < max_bits)
	{
		if (is_list_sorted(*a_list) == 1)
			break ;
		loop_every_element_a(a_list, b_list, i);
		i++;
	}
}
