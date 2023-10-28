/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:21:50 by fseles            #+#    #+#             */
/*   Updated: 2023/10/19 13:21:52 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//return 0 if there is something else than digit or -
// return 1 if everything is correct
static int	is_all_digit(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		if (arr[i][0] == '-')
			j++;
		if (ft_isdigit(arr[i][j]) != 1)
			return (0);
		while (arr[i][j] != '\0')
		{
			if (ft_isdigit(arr[i][j]) != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//return -1 if arr is empty,
//0 if it is not valid value (bigger than int ) 
//or if there is somthing else except 
//digits and '-' in first pos
static int	check_one(char *arg)
{
	char	**arr;

	arr = ft_split(arg, ' ');
	if (arr == NULL)
		return (-1);
	if (is_all_digit(arr) == 0 || is_valid_value(arr) == 0)
	{
		free_arr(arr);
		return (0);
	}
	free_arr(arr);
	return (1);
}

//check if input is valid both format like 1 2 3 and "34 57 89"
//return 0 if input is invalid
//retrn 1 if input is valid
int	is_valid(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		if (check_one(argv[1]) <= 0)
			return (0);
	}
	else
	{
		if (is_all_digit(argv + 1) == 0 || is_valid_value(argv + 1) == 0)
			return (0);
	}
	return (1);
}
