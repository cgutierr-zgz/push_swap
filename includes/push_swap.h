/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:11:48 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 19:35:24 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // NULL
# include <stdlib.h> // malloc, free
# include <stdio.h> // printf
# include <limits.h> // MAX_INT

typedef struct s_stack
{
	int				num;
	struct t_stack	*next;
}	t_stack;

// Main functions

// Util functions
void	print_error(t_stack *a, t_stack *b);
int		ft_atoi(const char *str);

// Stack functions
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **alst, t_stack *new);
void	ft_stackclear(t_stack **lst, void (*del)(void *));
void	ft_stackdelone(t_stack *lst);
void	ft_stackiter(t_stack *lst, void (*f)(void *));
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_lstmap(t_stack *ls, void *(*f)(void *), void (*dl)(void *));
t_stack	*ft_stacknew(int *num);
int		ft_stacksize(t_stack *lst);

#endif
