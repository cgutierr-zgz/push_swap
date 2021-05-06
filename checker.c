/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:03:18 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/06 16:10:32 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
//https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
int main(int argc, char **argv)
{
//	printf("%d\n", argc);
//	printf("%s", argv[1]);
	if(argc != 2)//(argc < 2 || argc > 2)
	{
		printf("demasiaos muchos o demasiaos pokos \n");
		return(1);
	}
	// split argv[1], ' ' -> con el n words
	int number_strings = ft_split_n(argv[1], ' ');
	// comprobar que todos sean integers
	char **numbers = ft_split(argv[1], ' ');


	// comprobar que no estén ni repetidos, ni sean > || < MAX_INT MIN_INT
	int i  = 0;

	while (i < number_strings)
	{
		printf("%s\n", numbers[i]);
		//check if it's a num
		int sopa;
		if(!(sopa = atoi(numbers[i]))) // comprobar isdigit primero !!!!
			printf("Erro sopator\n");
		// TODO:Check if->
		// if it's a num check if its  > || < MAX_INT MIN_INT
		i++;
	}
	// creamos un stack A Y v 
	// creamos un stack B del mismo tamaño
	int stack_a[number_strings];
	int stack_b[number_strings];

	
}
//    gcc checker.c utils1.c -o checker                  
// ARG="4 67 3 87 23"; ./checker $ARG  
//TODO: print functions to sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb