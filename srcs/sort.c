/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:42:58 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/04 11:57:44 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int *new_chunk(int *chunk, int num, int cantidad)
{
	int *sopa = malloc(sizeof(int *) * (cantidad - 1));
	int i = 0;
	while (i < cantidad - 1)
	{
		if (chunk[i] != num)
			sopa[i] = chunk[i];
		i++;
	}
	return sopa;
}

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

		//	printf("[%d]:%d\n", i, chunk[i]);
		i += 1;
	}
	//printf("\n");

	//HOLD1 -> numero mas bajo HOLD2 -> numero mas alto
	// BUCLE
	while (cantidad)
	{

		int hold1;
		i = 0;
		hold1 = chunk[i];
		while (i < cantidad)
		{
			if (hold1 > chunk[i])
				hold1 = chunk[i];

			i += 1;
		}
		int hold2;
		i = 0;
		hold2 = chunk[i];
		while (i < cantidad)
		{
			if (hold2 < chunk[i])
				hold2 = chunk[i];

			i += 1;
		}

		//	printf("HOLD1=%d\n", hold1);
		//	printf("HOLD2=%d\n", hold2);

		// QUÉ
		// Calcular que se tarda menos, si ra o rra en [hold1st] o [hold2nd]
		// hacer eso hasta que pa

		int nummoves1 = (0 - hold1) * -1;			 // ra
		int nummoves2 = ft_stacksize(ps->a) - hold2; // rrai
		int selected;
		if (nummoves1 > nummoves2)
		{
			selected = hold2;
			i = 0;
			while (i < nummoves2)
			{
				//	printf("hola\n");
				rule_rx_rrx(ps, 'a', 1, 1);
				i++;
			}
		}
		else
		{

			selected = hold1;
			i = 0;
			while (i < nummoves1)
			{
				//	printf("adeu\n");
				rule_rx_rrx(ps, 'a', 2, 1);
				i++;
			}
		}

		// borrar ese numero del array
		// hacer bucle cantidad --
		//BORRAR o hold1 o hold2 del array
		// ANTES DE HACER ESTO, MIRAR SI ps-b->num es mayor o menor



		
		// LUEGO ->
		rule_px(ps, 'b', 1);
		chunk = new_chunk(chunk, selected, cantidad);
		cantidad--;
	}
	// BUCLE
}
