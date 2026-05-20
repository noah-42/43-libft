/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	_Overview_
		Creates a new linked list node.

		Allocates memory for a 't_list' struct, stores the given 'content'
		in it, and sets 'next' to NULL.

	_NULL guard_
		A NULL guard is needed for the malloc() call --> if
			memory allocation fails --> the function returns NULL
			to prevent a crash (segmentation fault).

		Note that NULL guard is not needed for 'content' because NULL is
		a valid value to store in a node. The node simply holds a pointer and
		does not dereference 'content'.

	_Risks outside the function_
		- Caller forgets to free the node (memory leak)
		- Caller passes a pointer to freed-or-stack memory
			(undefined behavior, caller's responsibility)
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
	PSEUDO CODE
	1. Allocate memory for a new 't_list' node
	2. If malloc fails --> return NULL
	3. Store 'content' in 'new_node->content'
	4. Set 'new_node->next' to NULL
	5. Return the pointer to the new node
*/

/*
_Standaard outcome & potential edgecases_
+---------+--------------------+-------------------------+---------------------------+
|   Ex.   |      content       |       result node       |          notes            |
+---------+--------------------+-------------------------+---------------------------+
|    1    |    "hello"         | content="hello"         | basic usage               |
|         |                    | next=NULL               |                           |
+---------+--------------------+-------------------------+---------------------------+
|    2    |       NULL         | content=NULL            | valid node, no content    |
|         |                    | next=NULL               |                           |
+---------+--------------------+-------------------------+---------------------------+
|    3    |        ""          | content=""              | empty string is still a   |
|         |                    | next=NULL               | valid pointer             |
+---------+--------------------+-------------------------+---------------------------+
|    4    |    malloc fails    |     returns NULL        | allocation failure        |
+---------+--------------------+-------------------------+---------------------------+
|    5    |  &stack_variable   | content=address         | caller must ensure memory |
|         |                    | next=NULL               | stays valid               |
+---------+--------------------+-------------------------+---------------------------+
|    6    |  freed pointer     | content=dangling ptr    | undefined behavior        |
|         |                    | next=NULL               | (caller's responsibility) |
+---------+--------------------+-------------------------+---------------------------+
|    7    |  large allocation  | content=ptr             | e.g. large string or      |
|         |                    | next=NULL               | struct passed in          |
+---------+--------------------+-------------------------+---------------------------+
*/
