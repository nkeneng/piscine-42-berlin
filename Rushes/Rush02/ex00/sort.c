/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 01:48:12 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/18 02:32:41 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Function to convert number strings to integers and compare them
int	compare_numbers(char *num1, char *num2)
{
	long	n1;
	long	n2;

	n1 = ft_atol(num1);
	n2 = ft_atol(num2);
	if (n1 < n2)
		return (-1);
	if (n1 > n2) 
		return (1);
	return (0);
}

void	ft_swap(struct s_Dict *dict1, struct s_Dict *dict2)
{
	struct s_Dict	temp;

	temp = *dict1;
	*dict1 = *dict2;
	*dict2 = temp;
}

// Basic Bubble Sort implementation
void	sort_dict(struct s_Dict *dict, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size -1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (dict[j].digit > 2 || dict[j + 1].digit > 2)
			{
				if (dict[j].digit > dict[j + 1].digit)
					ft_swap(&dict[j], &dict[j + 1]); 
			}
			else
			{
				if (compare_numbers(dict[j].number, dict[j + 1].number) > 0)
					ft_swap(&dict[j], &dict[j + 1]); 
			}
			j++;
		}
		i++;
	}
}
