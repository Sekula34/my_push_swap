/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:03:25 by fseles            #+#    #+#             */
/*   Updated: 2023/10/18 12:03:30 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swapping first two elements
//prints sa if option is 1, if option is 2 sb, nothing if option is 0
void	swap(t_list **head_list, int option)
{
	int		elements;
	t_list	*first_element;
	t_list	*second_element;
	t_list	*third_element;

	elements = ft_lstsize(*head_list);
	if (elements <= 1)
		return ;
	first_element = *head_list;
	second_element = first_element->next;
	third_element = second_element->next;
	*head_list = second_element;
	second_element->next = first_element;
	first_element->next = third_element;
	if (option == 1)
		ft_printf("sa\n");
	if (option == 2)
		ft_printf("sb\n");
}

//swapping first two elements of both list a, and list b and write ss
void	ss(t_list **head_list_a, t_list **head_list_b)
{
	swap(head_list_a, 0);
	swap(head_list_b, 0);
	ft_printf("ss\n");
}

//push first element from source to dest and print 
//if option is 1 print pa if it is 2 print pb
//pa  Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
void	push(t_list **source_head, t_list **dest_head, int option)
{
	t_list	*move_element;
	t_list	*second_element_s;
	t_list	*first_elemet_d;

	move_element = *source_head;
	if (move_element == NULL)
		return ;
	second_element_s = move_element->next;
	*source_head = second_element_s;
	first_elemet_d = *dest_head;
	move_element->next = first_elemet_d;
	*dest_head = move_element;
	if (option == 1)
		ft_printf("pa\n");
	if (option == 2)
		ft_printf("pb\n");
}
