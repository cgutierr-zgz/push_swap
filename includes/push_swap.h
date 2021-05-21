/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgutierr <cgutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:11:48 by cgutierr          #+#    #+#             */
/*   Updated: 2021/05/20 21:31:43 by cgutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // NULL
# include <stdlib.h> // malloc, free
# include <stdio.h> // printf
# include <limits.h> // MAX_INT
# include <string.h> // strtok TODO: Implementar el mío

// TODO: Maybe implementar doblemente enlazadas
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	// Main stacks
	t_stack	*a;
	t_stack	*b;

	// Error managing
	int		index;	// Argumento global de entre todos
	int		arg;	// Argumento actual, auxiliar para ir avanzando
	char	**argv;	// Current argv we are checking
	int		aux;	// Int auxiliar para saber el índice del string actual
	char	c;		// Char actual del argumento
}	t_push_swap;

// Main functions
void	print_error(t_push_swap *ps, char *msg);

// Util functions
int		ft_atoi(const char *str, t_push_swap *ps)
char	*ft_strtok(char *str, const char *sep);

// Stack functions
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **alst, t_stack *new);
void	ft_stackclear(t_stack **lst, void (*del)(void *));
void	ft_stackdelone(t_stack *lst);
void	ft_stackiter(t_stack *lst, void (*f)(int));
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_lstmap(t_stack *ls, void (*dl)(void *));
t_stack	*ft_stacknew(int num);
int		ft_stacksize(t_stack *lst);

#endif
