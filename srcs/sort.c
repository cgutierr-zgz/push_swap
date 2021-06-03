/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:42:58 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/03 17:59:10 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Function to reverse the linked list */
static void reverse(t_stack *head_ref)
{
	t_stack *prev = NULL;
	t_stack *current = head_ref;
	t_stack *next = NULL;
	while (current != NULL)
	{
		// Store next
		next = current->next;

		// Reverse current node's pointer
		current->next = prev;

		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	head_ref = prev;
}

// Si el elemento ya existe en el array devuelve 1 si no, 0
int contains(int *array, int size, int num)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (array[i] == num)
			return (1);
		i++;
	}
	return (0);
}

// Obtenemos el número más pequeño que NO contenga el array ahora mismo
int get_smallest(t_stack *list, int *chunk, int cantidad)
{
	t_stack *current = list;
	long min;
	int position;
	int aux = 0; // 1?

	min = 2147483648;
	if (current)
	{
		if (!contains(chunk, cantidad, aux))
		{
			min = current->num;
			position = aux;
		}
		//printf("Min:%d\n", min);
		while (current != NULL)
		{
			//./push_swap 744 320 870 701 397 362
			if (min > current->num && !contains(chunk, cantidad, aux)) // current->num))
			//if (min > current->num && !contains(chunk, cantidad,  current->num))
			{
				min = current->num;
				position = aux;
			}
			aux += 1;
			current = current->next;
		}
	}
	//return (min);
	return (position);
}

void store_smallest(t_push_swap *ps, int *chunk, int cantidad)
{
	int i;

	i = 0;
	while (i < cantidad)
	{
		chunk[i] = get_smallest(ps->a, chunk, cantidad);

		printf("[%d]:%d\n", i, chunk[i]);
		i += 1;
	}
	printf("\n");

	// AHORA TENEMOS ALMACENADAS LAS POSICIONES DE LOS NÚMEROS
	// DE NUESTRO CHUNK DENTRO DE LA LISTA
	// TENEMOS QUE OBTENER
	/*
		HOLD1st = primer numero de nuestro array que encontremos desde arriba
		HOLD1nd = segundo número de nuestro array que encontremos desde abajo
	*/

	// Calcular que se tarda menos, si ra o rra en [hold1st] o [hold2nd]
	// hacer eso hasta que pa

	// borrar ese numero del array
	// hacer bucle cantidad --
}
