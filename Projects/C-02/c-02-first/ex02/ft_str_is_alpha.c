/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:29:51 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 19:03:01 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char *c);

int	ft_str_is_alpha(char *str)
{
	int	incr;

	incr = 0;
	while (str[incr] != '\0')
	{
		if (ft_isalpha(&str[incr]) == 0)
			return (0);
		incr++;
	}
	return (1);
}

int	ft_isalpha(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		return (1);
	else if (*c >= 'a' && *c <= 'z')
		return (1);
	return (0);
}
