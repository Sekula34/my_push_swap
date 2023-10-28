/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:32:46 by fseles            #+#    #+#             */
/*   Updated: 2023/10/19 16:32:48 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//return 1 if overflow happens, 0 if it is null
//return 0 if it is not 
static int	is_overflow(char *string)
{
	int	digit_number;

	if (string == NULL)
		return (0);
	digit_number = ft_strlen(string);
	if (string[0] == '-')
	{
		digit_number --;
		if (digit_number > 10)
			return (1);
		if (digit_number == 10)
			return (ft_strncmp(string + 1, "2147483648", 10));
		return (0);
	}
	if (digit_number > 10)
		return (1);
	if (digit_number == 10)
		return (ft_strncmp(string, "2147483647", 10));
	return (0);
}

//return 1 if values is valid, return 0 if oferflow happens
int	is_valid_value(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (is_overflow(argv[i]) > 0)
			return (0);
		i++;
	}
	return (1);
}
