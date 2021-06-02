/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/02 18:26:29 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_three(t_push_swap *ps)
{
	if (!check_order(ps->a) && ps->b == NULL)
		exit_push_swap(ps);
	if (ps->a->num > ps->a->next->num && ps->a->num < ps->a->next->next->num && ps->a->next->num < ps->a->next->next->num)
		rule_sx(ps, 'a', 1);
	else if (ps->a->num > ps->a->next->num && ps->a->num > ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
	{
		rule_sx(ps, 'a', 1);
		rule_rx_rrx(ps, 'a', 2, 1);
	}
	else if (ps->a->num > ps->a->next->num && ps->a->num > ps->a->next->next->num && ps->a->next->num < ps->a->next->next->num)
		rule_rx_rrx(ps, 'a', 1, 1);
	else if (ps->a->num < ps->a->next->num && ps->a->num < ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
	{
		rule_sx(ps, 'a', 1);
		rule_rx_rrx(ps, 'a', 1, 1);
	}
	else if (ps->a->num < ps->a->next->num && ps->a->num > ps->a->next->next->num && ps->a->next->num > ps->a->next->next->num)
		rule_rx_rrx(ps, 'a', 2, 1);
}

static void sort(t_stack **lst, int *position, t_stack **ptr, long *smaller)
{
	int aux;

	aux = 0;
	if (*lst)
	{
		while (*lst)
		{
			*ptr = (*lst)->next;
			if (*smaller == -2147483649)
				*smaller = (*lst)->num;
			if ((*lst)->num < *smaller)
			{
				*smaller = (*lst)->num;
				*position = aux;
			}
			aux += 1;
			*lst = *ptr;
		}
	}
}

void put_smaller_on_top(t_stack *lst, t_push_swap *ps)
{
	t_stack *ptr;
	long smaller;
	int position;
	int aux;
	int size;

	size = ft_stacksize(ps->a);
	smaller = -2147483649;
	position = 0;
	sort(&lst, &position, &ptr, &smaller);
	while (ps->a->num != smaller)
	{
		if (position >= (size / 2))
			rule_rx_rrx(ps, 'a', 2, 1);
		else
			rule_rx_rrx(ps, 'a', 1, 1);
	}
}

void sort_more(t_push_swap *ps, int size)
{
	int x;

	x = 0;
	while (x < size - 3)
	{
		put_smaller_on_top(ps->a, ps);
		rule_px(ps, 'b', 1);
		x++;
	}
	sort_three(ps);
	x = 0;
	while (x < size - 3)
	{
		rule_px(ps, 'a', 1);
		x++;
	}
}
#include <math.h>
void start_push_swap(int argc, char **argv, t_push_swap *ps)
{
	int size;

	size = ft_stacksize(ps->a);
	if (!check_order(ps->a))
		exit_push_swap(ps);
	else if (size == 2)
	{
		if (ps->a->num > ps->a->next->num)
			rule_sx(ps, 'a', 1);
	}
	else if (size == 3)
		sort_three(ps);
	else if (size <= 20)
		sort_more(ps, size);
	else
	{
		//TODO: Crear mi propio sqrt
		float chunksize = (size) / ((sqrt(size)) / 2);
		float chunkstart = 0;
		float chunkend = -1;
		printf("\n\nSize: %d\nChunk size: %f\n\n", size, chunksize);
		int numberofchunks = 1;
		while (1)
		{
			chunkstart = chunkend + 1;
			chunkend = chunkstart + round(chunksize);
			/*
			** TODO: Probar con estas dos lineas a ver si es más óptimo
			**			Esto lo que hace es sumar el último tramo, en lugar
			**			de crear un chunk más pequeño
			**		 Probar con [] > chunksize / 2 -> Se añade, si no, no
			**	if (chunkend + round(chunksize) > size)
			**		chunkend = size;
			*/
			if (chunkend > size)
				chunkend = size;
			chunkend -= 1;
			printf("Chunk nº%d:\t[%d]-[%d]\t: %d\n", numberofchunks, (int)chunkstart, (int)chunkend, ((int)chunkend - (int)chunkstart) + 1);

			// Añadir a chunk[numberofchunks - 1] los x números(round(chunksize)) más pequeños
			// Buscamos números del chunk[numberofchunks - 1] en [A]
			// hold1st -> scan [A] from the top until we find one chunk[numberofchunks - 1] number
			// hold2nd -> scan [A] from the bottom until we find one chunk[numberofchunks - 1] number
			// Movemos o hold1st o hold2nd arriba en función de cual tardemos menos en mover
			//	o bien con ra o con rra
			// Así hasta que no haya ningún número de chunk[numberofchunks - 1] en [A]
			// Repetimos esto con el resto de chunks

			if (chunkend >= (size - 1))
				break;
			numberofchunks++;
		}
		printf("\nNumber of chunks: %d\n", numberofchunks);
		// Buscamos el número más grande dentro de [B] y lo movemos arriba
		//	o bien con ra o con rra
		// Hacemos esto hasta que [B] esté vacío
	}
	exit_push_swap(ps);
}
