/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	_Overview_
		Adds a new node to the front (beginning) of a linked list.
		The new node becomes the first element of the list.

	_NULL guard_
		A NULL guard is needed for both 'lst' (the pointer to the pointer
		of the list) and 'new' (the node to add).

		If 'lst' is NULL --> there is no list to add to (crash).
		If 'new' is NULL --> there is no node to add (crash).

	_Risks_
		- Passing NULL for 'lst' or 'new' (crash without NULL guard)
		- Memory leak if caller loses reference to existing list
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
_PSEUDO CODE_
		1. If 'lst' or 'new' is NULL --> return (do nothing)
		2. Set 'new->next' to point to the current first node ('*lst')
		3. Update '*lst' to point to 'new' (new becomes first node)
*/

/*
+---------+------------+------------+-------------------------+---------------------------+
|   Ex.   |    lst     |    new     |      list after         |          notes            |
+---------+------------+------------+-------------------------+---------------------------+
|    1    |  [A]->NULL | [B]->NULL  | [B]->[A]->NULL          | add to existing list      |
+---------+------------+------------+-------------------------+---------------------------+
|    2    |   NULL     | [B]->NULL  | [B]->NULL               | add to empty list         |
+---------+------------+------------+-------------------------+---------------------------+
|    3    |  [A]->NULL |   NULL     | [A]->NULL               | no node to add, no change |
+---------+------------+------------+-------------------------+---------------------------+
|    4    |   NULL     |   NULL     | NULL                    | no crash, nothing happens |
+---------+------------+------------+-------------------------+---------------------------+
|    5    | [A]->[B]-> | [C]->NULL  | [C]->[A]->[B]->NULL     | add to front of multi-    |
|         |    NULL    |            |                         | node list                 |
+---------+------------+------------+-------------------------+---------------------------+
|    6    |    *lst    |   *lst     | lost reference to old   | undefined behavior        |
|         |  is NULL   |   is NULL  | list / crash            | (caller's responsibility) |
|         |  pointer   |  pointer   |                         |                           |
+---------+------------+------------+-------------------------+---------------------------+
*/
