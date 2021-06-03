/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:42:58 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/03 13:58:44 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Si el elemento ya existe en el array devuelve x si no, 0
int contains(int *array, int size, int elem)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (array[i] == elem)
			return i;
		i += 1;
	}
	return (0);
}
/*
temp = myList.head;
while (temp->next!=NULL){
  // do stuff with this element
  ...
  temp = temp->next; // get the next element
  }
*/
int get_smallest(t_push_swap *ps, int *chunk, int cantidad)
{
	t_stack *current = *head;
	int min;

	min = 0;
	if (*head)
	{
		min = (*head)->num;
		while (current != NULL)
		{
			if (min > current->num && !contains(chunk, cantidad, current->num))
				min = current->num;
			current = current->next;
		}
	}
	return (min);
}

static int sort_smallest(t_push_swap *ps, int *chunk, int cantidad)
{
	int aux;
	t_stack *ptr;
	long smaller;
	int position;

	smaller = get_smallest(&ps->a, chunk, cantidad);
	aux = 0;
	if (ps->a)
	{
		while (ps->a)
		{
			ptr = (ps->a)->next;
			if ((ps->a)->num < smaller && !contains(chunk, cantidad, (ps->a)->num))
			{
				smaller = (ps->a)->num;
				position = aux;
			}
			aux += 1;
			ps->a = ptr;
		}
	}
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
		chunk[i] = sort_smallest(ps, chunk, cantidad);
		printf("[%d]:%d\n", i, chunk[i]);
		i += 1;
	}
	printf("\n");
}
