/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/06/04 18:19:57 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void sort_three(t_push_swap *ps)
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

static void sort_smallest(t_stack **lst, int *position, t_stack **ptr, long *smaller)
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

static void put_smaller_on_top(t_stack *lst, t_push_swap *ps)
{
	t_stack *ptr;
	long smaller;
	int position;
	int aux;
	int size;

	size = ft_stacksize(ps->a);
	smaller = -2147483649;
	position = 0;
	sort_smallest(&lst, &position, &ptr, &smaller);
	while (ps->a->num != smaller)
	{
		if (position >= (size / 2))
			rule_rx_rrx(ps, 'a', 2, 1);
		else
			rule_rx_rrx(ps, 'a', 1, 1);
	}
}

static void sort_more(t_push_swap *ps, int size)
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
	else if (size <= 25) // <= 25 Poner
		sort_more(ps, size);
	else
	{
		float chunksize = (size) / ((sqrtme(size)) / 2);
		float chunkstart = 0;
		float chunkend = -1;
		//	printf("\n\nSize: %d\nChunk size: %f\n\n", size, chunksize);
		int numberofchunks = 1;
		int jj = 1;
		while (1)
		{
			jj += 1;
			printf("[%d] chunk!!!!\n", jj);
				print_stacks(ps);

			chunkstart = chunkend + 1;

			chunkend = chunkstart + roundme(chunksize);

			if (chunkend > size)
				chunkend = size;
			chunkend -= 1;
			//	printf("Chunk nº%d:\t[%d]-[%d] : %d\n", numberofchunks, (int)chunkstart, (int)chunkend, ((int)chunkend - (int)chunkstart) + 1);

			int *chunk = malloc(sizeof(int *) * ((int)chunkend - (int)chunkstart) + 1);

			store_smallest(ps, chunk, ((int)chunkend - (int)chunkstart) + 1);

			free(chunk);
			if (chunkend >= (size - 1))
				break;
			numberofchunks++;
		}

		print_stacks(ps);

		printf("AAAAA\n");

		t_stack *temp;
		temp = ps->b;
		int max;
		int pos;
		int aux = 0;
		if (temp)
		{
			max = temp->num;
			pos = aux;
			while (temp != NULL)
			{
				if (temp->num > max)
				{
					max = temp->num;
					pos = aux;
				}
				if (max == temp->num) //FIXME: algo mal tengo por aquí
					break;
				//printf("SOPA! %d\n", temp->num);
			}
			aux += 1;
			temp = temp->next;
		}

		// hacemos rb o rrb en funcion de que se tarda menos
		int xxx = 0;
		if (pos >= (size / 2))
		{
			while (xxx < ((size / 2) - pos))
			{
				rule_rx_rrx(ps, 'b', 2, 1);
				xxx++;
			}
		}
		else
		{
			while (xxx < ((0 - pos) * -1))
			{
				rule_rx_rrx(ps, 'b', 1, 1);
				xxx++;
			}
		}
		xxx = 0;
		while (xxx < size)
		{
			rule_px(ps, 'a', 1);
			xxx++;
		}

		print_stacks(ps);
		printf("size:%d", ft_stacksize(ps->a));
	}
	exit_push_swap(ps);
}
