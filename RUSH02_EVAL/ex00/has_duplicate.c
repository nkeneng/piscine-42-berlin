/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:01:29 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/18 20:01:47 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	if (s1[i] == s2[i])
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}

int	has_duplicates(struct s_Dict *dict, int dic_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < dic_len - 1) 
	{
		j = i + 1;
		while (j < dic_len - i) 
		{
			if (ft_strcmp(dict[i].number, dict[j].number) == 0)
				return (1); 
			j++;
		}
		i++;
	}
	return (0);
}
