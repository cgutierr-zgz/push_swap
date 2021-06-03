/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:42:58 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/03 15:52:12 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Copia de linbkedlist
t_stack *copyList(t_stack *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	else
	{

		// Allocate the memory for new Node
		// in the heap and set its data
		t_stack *newNode = (t_stack *)malloc(
			sizeof(t_stack));

		newNode->num = head->num;

		// Recursively set the next pointer of
		// the new Node by recurring for the
		// remaining nodes
		newNode->next = copyList(head->next);

		return newNode;
	}
}

// Si el elemento ya existe en el array devuelve x si no, 0
int contains(int *array, int size, int elem)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (array[i] == elem)
		{
			return i;
		}
		i += 1;
	}
	return (0);
}

// Obtenemos el número más pequeño que NO contenga el array ahora mismo
int get_smallest(t_stack *list, int *chunk, int cantidad)
{
	t_stack *current = list;
	int min;

	min = 0;
	if (list)
	{
		min = list->num;
		while (current != NULL)
		{
			if (min > current->num && (contains(chunk, cantidad, current->num) > 0))
			{
				min = current->num;
			}
			current = current->next;
		}
	}
	return (min);
}

// Añadimos los números más pequeños, que no estén ya en el earray
static int sort_smallest(t_stack *list, int *chunk, int cantidad)
{
	t_stack *ptr;
	int aux;
	long smaller;
	int position;

	smaller = get_smallest(list, chunk, cantidad);
	printf("Smaller GET: %ld\n", smaller);
	aux = 0;
	if (list)
	{
		while (list)
		{
			ptr = list->next;
			if (list->num < smaller && !contains(chunk, cantidad, list->num))
			{
				smaller = list->num;
				position = aux;
			}
			aux += 1;
			list = ptr;
		}
	}
	printf("Smaller: %ld\n", smaller);
	return smaller; // añadir posicion
}

void store_smallest(t_push_swap *ps, int *chunk, int cantidad)
{
	int i;

	i = 0;
	while (i < cantidad)
	{
		// TODO: Añadir n cantidad de ints menores de stack a chunk
		// Iterar por el chunk
		//print_stacks(ps);

		chunk[i] = sort_smallest(copyList(ps->a), chunk, cantidad);

		printf("[%d]:%d\n", i, chunk[i]);
		i += 1;
	}
	printf("\n");
	// HACER BUCLE AKI
	// hold 1st hold 2nd...
	// cantidad --
}
