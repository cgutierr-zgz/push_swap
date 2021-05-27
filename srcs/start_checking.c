/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:03:30 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/27 17:10:09 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	cases(t_push_swap *ps, char *line)
{
	if (ft_strcmp("ra", line))
		rule_rx_rrx(ps, 'a', 1, 0);
	else if (ft_strcmp("rb", line))
		rule_rx_rrx(ps, 'b', 1, 0);
	else if (ft_strcmp("rr", line))
		rule_rx_rrx(ps, 'r', 1, 0);
	else if (ft_strcmp("rra", line))
		rule_rx_rrx(ps, 'a', 2, 0);
	else if (ft_strcmp("rrb", line))
		rule_rx_rrx(ps, 'b', 2, 0);
	else if (ft_strcmp("rrr", line))
		rule_rx_rrx(ps, 'r', 2, 0);
	else if (ft_strcmp("pa", line))
		rule_px(ps, 'a', 0);
	else if (ft_strcmp("pb", line))
		rule_px(ps, 'b', 0);
	else
	{
		ps->argv = line;
		print_error(ps, "Bad instruction");
	}
}

static int	reading(int *n, char **line)
{
	*n = get_next_line(0, line);
	return (*n);
}

void	start_checking(int argc, char **argv, t_push_swap *ps)
{
	int		n;
	char	*line;

	while (reading(&n, &line) > 0)
	{
		if (ft_strcmp("sa", line))
			rule_sx(ps, 'a', 0);
		else if (ft_strcmp("sb", line))
			rule_sx(ps, 'b', 0);
		else if (ft_strcmp("ss", line))
			rule_sx(ps, 's', 0);
		else
			cases(ps, line);
		free(line);
		if (n == 0)
			break ;
	}
	if (check_order(ps->a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	exit_push_swap(ps);
}
