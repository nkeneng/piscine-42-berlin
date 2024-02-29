/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:10:59 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/05 15:34:51 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr);
void	ft_ultimate_ft(int *********nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_ultimate_div_mod(int *a, int *b);
void	ft_putstr(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);
int	ft_strlen(char *str);

int	main(void)
{
	int	numbers[5];
	int	incr;

	incr = 0;
	ft_ft(&incr);
	ft_swap(&incr, &incr);
	ft_div_mod(incr, incr, &incr, &incr);
	ft_ultimate_div_mod(&incr, &incr);
	ft_putstr("hello marvin");
	ft_strlen("hello world");
	ft_rev_int_tab(numbers, 5);
	ft_sort_int_tab(numbers, 5);
	while (incr < 5)
	{
		printf("the value is %d \n", numbers[incr]);
		incr++;
	}
	return (0);
}
