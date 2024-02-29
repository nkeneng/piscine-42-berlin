/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:26:16 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 19:13:44 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_special_character(char c);

char	*ft_strcapitalize(char *str)
{
	int	incr;
	int	word_begin;

	incr = 0;
	word_begin = 1;
	while (str[incr] != '\0')
	{
		if (word_begin == 1)
		{
			if (str[incr] >= 'a' && str[incr] <= 'z')
				str[incr] -= 32;
			word_begin = 0;
		}
		else if (word_begin == 0)
			if (str[incr] >= 'A' && str[incr] <= 'Z')
				str[incr] += 32;
		if (is_special_character(str[incr]))
			word_begin = 1;
		incr++;
	}
	return (str);
}

int	is_special_character(char c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	else if (c >= 'A' && c <= 'Z')
		return (0);
	else if (c >= '0' && c <= '9')
		return (0);
	return (1);
}
