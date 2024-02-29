/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:39:43 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/20 11:39:55 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	incr;

	incr = 0;
	if (argc <= 0)
		return (-1);
	while (argv[0][incr])
	{
		write(1, &argv[0][incr], 1);
		incr++;
	}
	write(1, "\n", 1);
	return (0);
}
