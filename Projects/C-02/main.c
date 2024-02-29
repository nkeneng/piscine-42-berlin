/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:38:25 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/06 17:37:54 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char*	ft_convert_to_hex(int i);
char	*ft_strcapitalize(char *str);
int	ft_str_is_alpha(char *str);
int	ft_str_is_numeric(char *str);
int	ft_str_is_printable(char *str);
char *ft_strupcase(char *str);
int	is_special_character(char c);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
void ft_putstr_non_printable(char *str);

int	main(void)
{
	char	a[] = "";
	char	b[13];


	char	*d = "hello world my bro , here is steven";

	//char c = '\\n'-'0';
	//int val = c;
	//write(1, &c, 1);
	//printf(" \n %d ", val);
	//if ('\0'-'0' == '\0')
	//	printf("here we are");
	
	//ft_convert_to_hex(10);
	//ft_putstr_non_printable("aa \x01");
	ft_putstr_non_printable("Coucou\ntu vas bien");
	write(1, "\n", 2);
	ft_putstr_non_printable("\x1F");
	//int data = ft_str_is_printable(a);
	//ft_strcpy(b, a);
	//ft_strncpy(b, a, 3);
	//int data = ft_str_is_alpha(a);
	//int data = ft_str_is_numeric(a);
	//printf("%s \n ", b);
	//ft_strupcase(d);	
	//printf("the original str was : %s \n ", b);
	//unsigned int data = ft_strlcpy(b, d, 13);
	//printf("the copied str is : \"%s\" \n ", b);
	//printf("the len is %d \n",data);
	//ft_strcapitalize(d);
	//int data = is_special_character(' ');	
	return (0);
}
