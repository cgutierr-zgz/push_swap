/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:42:58 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/08 20:56:56 by cgutierr         ###   ########.fr       */
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
		//Añadimos x cantidad de smallest nums al array
		chunk[i] = get_smallest(ps->a, chunk, cantidad);
		printf("[%d]:%d\n", i, chunk[i]);
		i += 1;
	} // HASTA AQUI PARECE TODO OK
	  //printf("\n");

	// AKI YA NO OK
	int contador = 0;
	while (cantidad)
	{
		if (!cantidad)
			break;
		/*
		while (contador < cantidad)
		{
			//Añadimos x cantidad de smallest nums al array
			printf("[%d]:%d\n", contador, chunk[contador]);
			contador += 1;
		}*/
		// chunk = malloc (cantidad - 1); quitar el numero x
		// TODO: Antes de hacer esto, hacer una copia del array
		// SIN o HOLD1 o HOLD 2, en función de que usemos ///// SU POSICIÓN
		chunk = malloc(sizeof(int *) * cantidad);
		// TODO:FIXME:Mirar si tal vez hold1 y hold2 son iguales
		int hold1 = chunk[0];
		int hold2 = chunk[cantidad - 1];

		int pos1 = (0 - hold1) * -1; // xd es lo mismo que hold1
		int pos2 = ft_stacksize(ps->a) - hold2;

		if (pos2 > pos1)
		{
			// Es porque tardamos menos en mover el numero en x posicion
			// ra hasta ponerle arriba
			// por cada ra **restarle** 1 a cada posicion y si es size -> 0
			// y si es -1 es size
		}
		else
		{

			// Es porque tardamos menos en mover el numero en x posicion
			// rra hasta ponerle arriba
			// por cada rra **sumarle** 1 a cada posicion y si es size -> 0
			// y si es -1 es size
		}

		// ANTES DE HACER PB TENEMOS QUE:::::
		/*
			So the correct number is now on to top of Stack A.
			But there are two things we need to check for before we push
			the number over to Stack B. You have to check if the number you’re pushing
			is either bigger or smaller than all the other numbers in Stack B.
			Since we’re not just pushing the smallest number one at a time. We need to
			make sure we’re not gonna cause an infinite loop by trying to find
			the perfect spot to insert that number.
		*/
		rule_px(ps, 'b', 1);
		cantidad--;
		// TODO: QUITAR O HOLD 1 o HOLD 2 del array final
	}
}
/*
	while (cantidad >= 0) // FIXME: o > 0 simplemente
	{
		if (cantidad == 0)
			break;
		int hol1pos = chunk[0];
		int hol2pos = chunk[cantidad - 1];

		//	printf("HOLD1=%d\n", hold1);
		//	printf("HOLD2=%d\n", hold2);

		int nummoves1 = (0 - hol1pos) * -1;			   // ra
		int nummoves2 = ft_stacksize(ps->a) - hol2pos; // rrai
		int selected;
		if (nummoves1 > nummoves2)
		{
			selected = hol2pos;
			i = 0;
			// POSICIONES DE TODOS ++
			// Y TAL
			int mover = 0;
			while (mover < cantidad)
			{
				chunk[mover] += 1;
				if (chunk[mover] >= ft_stacksize(ps->a) - 1)
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
			selected = hol1pos;
			i = 0;
			// POSICIONES DE TODOS --
			// Y TAL
			int mover = 0;
			while (mover < cantidad)
			{
				chunk[mover] -= 1;
				if (chunk[mover] <= 0)
					chunk[mover] = ft_stacksize(ps->a) - 1;
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
		if (posa >= ((ft_stacksize(ps->b) / 2) - 1))
		{
			posa = (ft_stacksize(ps->b) - 1) - posa;
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
		if (!ps->b)
		{
			rule_px(ps, 'b', 1);
		}
		else
		{
			if (ps->b->num > ps->a->num)
				rule_px(ps, 'b', 1);
			else
			{
				rule_px(ps, 'b', 1);
				rule_rx_rrx(ps, 'b', 1, 1);
			}
		}
		chunk = new_chunk(chunk, selected, cantidad);
		printf("!!CANTIDAD: %d\n", cantidad);
		print_stacks(ps);
		cantidad--;
	}

*/
