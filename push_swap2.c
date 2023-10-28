/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:28:01 by fseles            #+#    #+#             */
/*   Updated: 2023/10/25 20:28:03 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// : Shift up all elements of stack a by 1.
//The first element becomes the last one.
//print ra if option is 1, rb if option is 2
void	rotate(t_list **head, int option)
{
	t_list	*first_element;
	t_list	*second_element;
	t_list	*old_last_element;
	int		noe;

	noe = ft_lstsize(*head);
	if (noe <= 1)
		return ;
	first_element = *head;
	second_element = first_element->next;
	old_last_element = ft_lstlast(*head);
	*head = second_element;
	old_last_element->next = first_element;
	first_element->next = NULL;
	if (option == 1)
		ft_printf("ra\n");
	if (option == 2)
		ft_printf("rb\n");
}

//rotate both a and b list and print rr
void	rr(t_list **head_a, t_list **head_b)
{
	rotate(head_a, 0);
	rotate(head_b, 0);
	ft_printf("rr\n");
}

//Shift down all elements of stack a by 1.
//The last element becomes the first one.
//print rra if option is 1 or rrb if option is 2
void	reverse_rotate(t_list **head_a, int option)
{
	int		noe;
	t_list	*first_element;
	t_list	*penultimate_element;
	t_list	*last_element;

	noe = ft_lstsize(*head_a);
	if (noe <= 1)
		return ;
	first_element = *head_a;
	last_element = ft_lstlast(*head_a);
	penultimate_element = first_element;
	while (penultimate_element->next->next != NULL)
		penultimate_element = penultimate_element->next;
	penultimate_element->next = NULL;
	*head_a = last_element;
	last_element->next = first_element;
	if (option == 1)
		ft_printf("rra\n");
	if (option == 2)
		ft_printf("rrb\n");
}

//reverse rotate both a and b and print rrr
void	rrr(t_list **head_a, t_list **head_b)
{
	reverse_rotate(head_a, 0);
	reverse_rotate(head_b, 0);
	ft_printf("rrr\n");
}
