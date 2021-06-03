/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:42:58 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/03 17:49:15 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Function to reverse the linked list */
static void reverse(t_stack **head_ref)
{
	t_stack *prev = NULL;
	t_stack *current = *head_ref;
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
	*head_ref = prev;
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

	/*
	 * 
	 * HOLD 1st = RECORREMOS LA LISTA DESDE ARRIBA Y VEMOS SI
	 * ENCONTRAMOS UNO DE LOS NÚMEROS DE ARRAY
	 * SI ES ASÍ, NOS VALE => OUT -> HOLD1st
	 * 
	 * 
	 * HOLD 2nd = RECORREMOS LA LISTA DESDE ABAJO Y BUSCAMOS
	 * UNO DE LOS NUMEROS DEL ARRAY
	 * CUALQUIERA ES OK => OUT -> HOLD2nd
	 * 
	 * 
	 * 
	 * 
	 */

	int hold_first;
	t_stack *temp = ps->a;

	if (temp)
	{
		while (temp)
		{
			if (contains(chunk, cantidad, temp->num))
			{
				hold_first = temp->num;
				break;
			}
			temp = temp->next;
		}
	}

	int hold_2nd;
	temp = ps->a;
	reverse(&temp);

	// FIXME: Hacer esto de atrás palante
	if (temp)
	{
		while (temp)
		{
			if (contains(chunk, cantidad, temp->num) && temp->num != hold_first)
			{
				hold_2nd = temp->num;
				break;
			}
			temp = temp->next;
		}
	}

	printf("1st:%d, 2nd:%d\n", (int)hold_first, (int)hold_2nd);

	//TODO: hold2nd está mal
	// Calcular que se tarda menos, si ra o rra en [hold1st] o [hold2nd]
	// hacer eso hasta que pa
	// cantidad --
	// borrar ese numero del array
	// hacer bucle cantidad --
}
