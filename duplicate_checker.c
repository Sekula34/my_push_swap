/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:20:16 by fseles            #+#    #+#             */
/*   Updated: 2023/10/25 20:20:18 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//checks if value is somwhere in list 
//return 1 if value is found in list 
// reuturn 0 if that value is not in list
int	check_one_value(int value, t_list *head_a2)
{
	t_data	*p_data;
	int		value_to_check;

	head_a2 = head_a2->next;
	while (head_a2 != NULL)
	{
		p_data = (t_data *)head_a2->content;
		value_to_check = p_data->original_value;
		if (value == value_to_check)
		{
			return (1);
		}
		head_a2 = head_a2->next;
	}
	return (0);
}

//checks if there is even one duplicatete value in list
//checks original value not relative
//return 1 if there is duplicate
//return 0 if there is none
int	duplicate_checker(t_list *head_a)
{
	t_data	*p_data;

	while (head_a->next != NULL)
	{
		p_data = (t_data *)head_a->content;
		if (check_one_value(p_data->original_value, head_a) == 1)
		{
			return (1);
		}
		head_a = head_a->next;
	}
	return (0);
}
