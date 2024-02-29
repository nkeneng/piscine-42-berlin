/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:36:41 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 20:36:44 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>


void	test_int_array(int *arr)
{
	char a;
	int	incr = 0;
	while (arr[incr] != '\0')
	{
		printf("\n the ptr value is %d \n", arr[incr]);
		//a = '0' + *ptr1++;
		a = '0' + arr[incr];
		incr++;
		write(1, &a, 1);
	}



void	compare_string()
{

    char str1[] = "";
    char str2[] = "abcg";
    
    int result = strcmp(str1, str2);
    int result2 = strncmp(str1, str2,-1);
    
   	if (result2 == 0) {
        printf("The strings are equal. %d\n", result2);
    } else if (result2 < 0) {
        printf("str1 is less than str2. %d\n", result2);
    } else {
        printf("str1 is greater than str2. %d\n",result2);
    }
}

void	check_write(char *str)
{
	int	incr;

	incr = 0;
	while (str[incr] != '\0')
	{
		incr++;
	}
	str[11] = 'S';
	str[12] = 'S';
	str[13] = 'S';
	str[14] = '\0';
	printf("the size is %d\n",incr);
}

 int	main(void)
{
	char c[11] = "hello world";
	check_write(c);
	printf("%s\n",c);
	return (0);
}
