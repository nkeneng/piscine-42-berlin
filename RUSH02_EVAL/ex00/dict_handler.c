/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:36:59 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/18 19:42:30 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include <stdio.h>

/*void	print_dict(struct s_Dict *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("Entry %d:\n", i);
		printf("  Number: %s\n", dict[i].number);
		printf("  Word: %s\n", dict[i].word);
		printf("  Digits: %d\n", dict[i].digit);
		i++;
	}
}
*/

int	do_something(char c, char c1)
{
	if (c1 == '\0' || (c == '\n' && (c1 != '\0' && c1 != '\n')))
		return (1);
	return (0);
}

void	fill_data(int size, char **arr, char *str)
{
	*arr = malloc((size + 1) * sizeof(char));
	if (*arr == NULL)
	{
		return ;
	}
	ft_strncpy(*arr, str, size);
	(*arr)[size] = '\0';
}

void	ft_init(int *i, int *nb_s, int *wd_s, int *l_i)
{
	*i = 0;
	*nb_s = -1;
	*wd_s = -1;
	*l_i = 0;
}

void	extract_dic_elements(char *str, struct s_Dict *dict)
{
	int	i;
	int	nb_s;
	int	wd_s;
	int	l_i;

	ft_init(&i, &nb_s, &wd_s, &l_i);
	while (str[i])
	{
		if (nb_s < 0)
			nb_s = i;
		if (str[i] == ':')
		{
			fill_data(i - nb_s, &dict[l_i].number, &str[nb_s]);
			dict[l_i].digit = i - nb_s;
			wd_s = i + 1;
		}
		if (do_something(str[i], str[i + 1]))
		{
			fill_data(i - wd_s, &dict[l_i].word, &str[wd_s]);
			l_i++;
			wd_s = -1;
			nb_s = -1;
		}
		i++;
	}
}

int	find_from_digit(int digit, struct s_Dict *dict, int size)
{
	int	incr;

	incr = 0;
	while (incr < size)
	{
		if (dict[incr].digit == digit)
			return (incr);
		incr++;
	}
	return (-1);
}
