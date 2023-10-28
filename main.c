/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:33:49 by fseles            #+#    #+#             */
/*   Updated: 2023/10/18 12:33:52 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//deleting content of node t_data 
void	delete_data(void *p)
{
	t_data	*value;

	value = (t_data *) p;
	free(value);
}

//check for errors with input
//return 1 if error happens and print Error on fd 2
//return 0 if everything is ok
int	is_error(int argc, char *argv[], t_list **list_a)
{
	if (is_valid(argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (initialize_list(argc, argv, list_a) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (duplicate_checker(*list_a) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc <= 1)
		return (0);
	if (is_error(argc, argv, &list_a) == 1)
	{
		ft_lstclear(&list_a, delete_data);
		ft_lstclear(&list_b, delete_data);
		return (0);
	}
	set_relative_value(list_a);
	sorter(&list_a, &list_b);
	ft_lstclear(&list_a, delete_data);
	ft_lstclear(&list_b, delete_data);
	return (0);
}
// void printaj(void *p)
// {
// 	t_data *value;
// 	value = (t_data *) p;
// 	ft_printf("Originalna vrijednost je %d\n", value->original_value);
// 	ft_printf("Relativna vrijednost je %d\n\n", value->relative_value);
// }

// int	main2(int argc, char *argv[])
// {
// 	//t_data *p;
// 	// t_list *head_a;
// 	// head_a = NULL;
// 	if (is_valid(argc, argv) <= 0)
// 	{
// 		//delete this
// 		ft_printf("not valid input \n");
// 		return (0);
// 	}
// 	ft_printf("valid input \n");
//    // Create data for two elements
// 	t_list *list = NULL;
// 	t_list *list_b = NULL;
// 	if(initialize_list(argc, argv, &list) == -1)
// 	{
// 		ft_lstiter(list, printaj);
// 		ft_lstclear(&list, delete_data);
// 		ft_lstclear(&list_b, delete_data);
// 		return (0);
// 	}
// 	if(duplicate_checker(list) == 1)
// 	{
// 		ft_printf("erorcic s duplikatima");
// 		ft_lstclear(&list, delete_data);
// 		ft_lstclear(&list_b, delete_data);
// 		return (0);
// 	}

//     // t_data *data1 = malloc(sizeof(t_data));
//     // data1->original_value = 42;
//     // data1->relative_value = 10;

//     // t_data *data2 = malloc(sizeof(t_data));
//     // data2->original_value = 88;
//     // data2->relative_value = 20;

// 	// t_data *data3 = malloc(sizeof(t_data));
// 	// data3->original_value = 34;
// 	// data3->relative_value = 1; 

//     // // Create linked list nodes and add them to the list
//     // t_list *list = NULL;
//     // t_list *node1 = ft_lstnew(data1);
//     // t_list *node2 = ft_lstnew(data2);
// 	// t_list *node3 = ft_lstnew(data3);
//     // ft_lstadd_front(&list, node1);
//     // ft_lstadd_front(&list, node2);
// 	// ft_lstadd_front(&list, node3);

// 	set_relative_value(list);
// 	if (is_list_sorted(list) == 1)
// 	{
// 		ft_printf("lista je sortirana\n");
// 	}
// 	else 
// 	{
// 		ft_printf("nije soritrano na pocetku \n");
// 	}
//     // Use ft_lstiter to print the values
// 	ft_printf("Broj elemenata u listi je %d\n", ft_lstsize(list));
//     ft_lstiter(list, printaj);
// 	ft_printf("Sad krece sortiranje \n");

// 	ft_printf("prvo hardcode\n");
// 	sorter(&list, &list_b);
// 	ft_printf("gotov hardcore\n");

// 	// ft_printf("sad cu zamijenti prva dva\n");
// 	// swap(&list);
// 	// ft_printf("Broj elemenata u listi je %d\n", ft_lstsize(list));
//     // ft_lstiter(list, printaj);

// 	// ft_printf("Sada cu spucat prvi element s a 
//liste da bude prvi element b liste\n");
// 	// push(&list, &list_b);
// 	// ft_printf("lista a \n");
// 	// ft_lstiter(list, printaj);
// 	// ft_printf("Lista b\n");
// 	// ft_lstiter(list_b, printaj);
// 	// ft_printf("Rotacija a prvi element postaje zadnji\n");
// 	// rotate(&list);
// 	// ft_printf("obrnuta rotacija zadnji element postaje prvi\n");
// 	// reverse_rotate(&list,1);
// 	ft_lstiter(list, printaj);
// 	ft_lstclear(&list, delete_data);
// 	ft_lstclear(&list_b, delete_data);
//     // Free allocated memory (don't forget to free memory when you're done)
// 	// free(data1);
//     // free(data2);
// 	// free(node1);
//     // free(node2);
//     return 0;
// }