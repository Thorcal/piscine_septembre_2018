/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 11:50:22 by spuisais          #+#    #+#             */
/*   Updated: 2018/09/16 19:25:51 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split_whitespaces(char *str);
int		ft_atoi(char *str);

char	*return_expr(char *str, int debutexpr, int finexpr)
{
	char *newexpr;
	int size;
	int i;

	size = finexpr - debutexpr;
	newexpr = (char*)malloc(sizeof(char) * (size));
	i = 0;
	while (i < size)
	{
		newexpr[i] = str[debutexpr];
		i++;
		debutexpr++;
	}
	return(newexpr);
}

char	calc_multiply(int num1, int num2)
{
	char *resultchar;
	int result;

	result = num1 * num2;	
}

void reverse(char str[], int length) 
{ 
	int start = 0; 
	int end = length -1; 
	while (start < end) 
	{ 
		swap(*(str+start), *(str+end)); 
		start++; 
		end--; 
	} 
}

char	*ft_itoa(int num, char *str, int base) 
{ 
	int i = 0;

	if (num == 0) 
	{ 
		str[i++] = '0'; 
		str[i] = '\0'; 
		return str; 
	} 
	while (num != 0) 
	{ 
		int rem = num % base; 
		str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
		num = num/base; 
	} 
	str[i] = '\0'; 
	reverse(str, i);
	return str;
}

int		calc_expr(char *str, int debutexpr, int finexpr, int primary_op)
{
	int i;
	int j;
	int num1;
	int num2;
	int result;

	i = 0;
	j = 0;
	num1 = 0;
	num2 = 0;
	result = 0;
	while (primary_op > 0)
	{
		if (str[i] == '*')
		{
			j = i;
			i += 2;
			while (str[i] >= '0' && str[i] <= '9')
			{
				printf("char = %c | int = %d\n", str[i], str[i] - '0');
				num2 = num2 * 10 + str[i] - '0';
				i++;
			}
			j -= 2;
			while (str[j] != ' ')
				j--;
			j++;
			while (str[j] >= '0' && str[i] <= '9')
			{
				printf("char = %c | int = %d\n", str[j], str[j] - '0');
				num1 = num1 * 10 + (str[j] - '0');
				j++;
			}
			calc_multiply(num1, num2);	
			printf("num 1 = %d | num 2 = %d\n", num1, num2);
			primary_op--;
		}
		i++;		
	}
	return 0;
}

char	*replace_str(char *str, char *num, int debutexpr, int finexpr)
{
	int i;
	int j;

	i = finexpr;
	j = 0;
	while (num[j] != '\0')
		j++;
	j--;
	while (j >= 0)
	{
		printf("i = [%d] & [%c] | j = [%d] & [%c]\n", i, str[i], j, num[j]);
		str[i] = num[j];
		i--;
		if (j != 0)
			j--;
		else
			break ;
	}
	while(i >= debutexpr)
	{
		printf("i = [%d] & [%c] | j = [%d] & [%c]\n", i, str[i], j, num[j]);
		str[i] = ' ';
		i--;
	}
	printf("str = %s | num = %s", str, num);
	return(num);
}

/*int		eval_expr(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		
	}
	while (str[i] != '\0')
	{
		while (str[i] != ')')
			i++;
		finexpr = i;
		j = finexpr;
		while (j > 0)
		{
			if (str[j] == '(')
				debutexpr = j;
			j--;
		}
		i++;
	}
	printf("debut expr = %d | fin expr = %d\n", debutexpr, finexpr);
	//replace_str(str);
	split_expr(str, debutexpr, finexpr);
	return (0);
}*/

void	check_priority(char *str, int debutexpr, int finexpr)
{
	int i;
	int j;
	int parenthesis;
	int primary_op;
	printf("Check priority of '%s'\nFrom %d to %d\n", str, debutexpr, finexpr);
	i = debutexpr;
	parenthesis = 0;
	primary_op = 0;
	while (i < finexpr)
	{
		if (str[i] == ')')
			parenthesis++;
		i++;
	}
	i = debutexpr;
	while (i < finexpr)
	{
		if (str[i] == '*' || str[i] == '/' || str[i] == '%')
			primary_op++;
		i++;
	}
	i = debutexpr;
	while (i < finexpr)
	{
		if (parenthesis > 0)
		{
			while (str[i] != ')')
				i++;
			finexpr = i + 1;
			j = finexpr;
			while (j > 0)
			{
				if (str[j] == '(')
					debutexpr = j;
				j--;
			}
			i++;
			check_priority(return_expr(str, debutexpr, finexpr), debutexpr, finexpr);
		}
		else
		{
			
		}
	}
}



int 	main(int ac, char **av)
{
	//eval_expr(av[1]);
	
	calc_expr(av[1], 0, strlen(av[1]), 1);
	return (0);
}

























