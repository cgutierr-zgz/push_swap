/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:42:58 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/04 16:20:00 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int *new_chunk(int *chunk, int num, int cantidad)
{
	int *sopa = malloc(sizeof(int *) * (cantidad - 1));
	int i = 0;
	int i2 = 0;
	while (i < cantidad)
	{
		if (chunk[i] != num)
		{

			sopa[i2] = chunk[i];
			//printf("[%d]:%d\n", i, sopa[i2]);
			i2++;
		}
		i++;
	}
	//free(chunk);
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
	int aux = 0;

	min = 2147483648;
	if (current)
	{
		if (!contains(chunk, cantidad, aux))
		{
			min = current->num;
			position = aux;
		}
		while (current != NULL)
		{
			if (min > current->num && !contains(chunk, cantidad, aux))
			{
				min = current->num;
				position = aux;
			}
			aux += 1;
			current = current->next;
		}
	}
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
	while (cantidad >= 0)
	{
		if (cantidad == 0)
			break;

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

		int nummoves1 = (0 - hold1) * -1;			 // ra
		int nummoves2 = ft_stacksize(ps->a) - hold2; // rrai
		int selected;
		if (nummoves1 > nummoves2)
		{
			selected = hold2;
			i = 0;
			// POSICIONES DE TODOS ++
			// Y TAL

			int mover = 0;
			while (mover < cantidad)
			{
				chunk[mover] += 1;
				if (chunk[mover] >= ft_stacksize(ps->a))
					chunk[mover] = 0;

				mover++;
			}

			while (i < nummoves2)
			{
				rule_rx_rrx(ps, 'a', 1, 1);
				i++;
			}
		}
		else
		{

			selected = hold1;
			i = 0;
			// POSICIONES DE TODOS --
			// Y TAL
			int mover = 0;
			while (mover < cantidad)
			{
				chunk[mover] -= 1;
				if (chunk[mover] <= 0)
					chunk[mover] = ft_stacksize(ps->a);

				mover++;
			}
			while (i < nummoves1)
			{
				rule_rx_rrx(ps, 'a', 2, 1);
				i++;
			}
		}

		t_stack *tmporb;

		tmporb = ps->b;
		int min;
		int posa, aaaux;
		aaaux = 0;
		if (tmporb)
		{
			min = tmporb->num;
			posa = aaaux;
			while (tmporb != NULL)
			{
				if (tmporb->num < min)
				{
					min = tmporb->num;
					posa = aaaux;
				}
				if (tmporb->num == min)
					break;
			}
			aaaux += 1;
			tmporb = tmporb->next;
		}
		int contasion = 0;
		if (posa >= (ft_stacksize(ps->b) / 2))
		{
			posa = ft_stacksize(ps->b) - posa;
			while (contasion < posa)
			{
				rule_rx_rrx(ps, 'b', 2, 1);
				contasion++;
			}
		}
		else
		{
			posa = (0 - posa) * -1;
			while (contasion < posa)
			{
				rule_rx_rrx(ps, 'b', 1, 1);
				contasion++;
			}
		}

		// LUEGO ->
		rule_px(ps, 'b', 1);
		chunk = new_chunk(chunk, selected, cantidad);
		cantidad--;
	}
	//	printf("SOPA\n");
	// BUCLE
}
