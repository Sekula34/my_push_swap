/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:05:46 by fseles            #+#    #+#             */
/*   Updated: 2023/10/18 12:05:49 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_data
{
	int	original_value;
	int	relative_value;
}	t_data;

int		duplicate_checker(t_list *head_a);
void	free_arr(char **arr);
void	four_element_sorter(t_list **list_a, t_list **list_b);
int		get_position_of_lowest(t_list *list_a);
void	group_commands(t_list **list_a, t_list **list_b);
void	group_commands2(t_list **list_a, t_list **list_b);
int		initialize_list(int argc, char **argv, t_list **head_a);
int		is_list_sorted(t_list *head);
int		is_valid(int argc, char *argv[]);
int		is_valid_value(char **argv);
void	push(t_list **source_head, t_list **dest_head, int option);
void	radix_sort(t_list **a_list, t_list **b_list);
void	reverse_rotate(t_list **head_a, int option);
void	rotate(t_list **head, int option);
void	rr(t_list **head_a, t_list **head_b);
void	rrr(t_list **head_a, t_list **head_b);
void	set_relative_value(t_list *head);
void	ss(t_list **head_list_a, t_list **head_list_b);
void	swap(t_list **head_list, int option);
void	sorter(t_list **list_a, t_list **list_b);
void	three_element_sorter(t_list **list_a);

#endif
