/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	_Overview_
		Allocates sufficient memory for a copy of the string 's', does the
		copy, and returns a pointer to it.

	_Safety Profile_
		Checks whether the allocation of memory was succesful.

	_ NULL guard_
		Returns NULL if there is insufficient memory (aka allocation failure
	check).

	_Return value_
		- Returns a pointer to the copy of the 's' --> 'dup'.
		  --> this pointer may subsequently be used as an argument for free()
				to the program or function that calls ft_strdup

*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len + 1);
	return (dup);
}

/*
	PSEUDO CODE
	1. Get the length of 's' via ft_strlen()
	2. Allocate 'len + 1' bytes (for string + null terminator)
	3. If malloc fails --> return NULL
	4. Copy all bytes from 's' to 'dup' (including '\0')
		via ft_memcpy
	5. Return pointer to 'dup'
*/

/*
__ Scenarios & cases __
+---------+----------------+------------------+---------------------------+
|   Ex.   |       s        |     result       |          notes            |
+---------+----------------+------------------+---------------------------+
|    1    |    "hello"     |     "hello"      | basic usage               |
+---------+----------------+------------------+---------------------------+
|    2    |       ""       |       ""         | empty string, still valid |
+---------+----------------+------------------+---------------------------+
|    3    | "Hello\tWorld" | "Hello\tWorld"   | special characters        |
+---------+----------------+------------------+---------------------------+
|    4    | malloc fails   |     NULL         | insufficient memory       |
+---------+----------------+------------------+---------------------------+
|    5    |    "hello"     | ptr != s         | copy is independent from  |
|         |                |                  | original                  |
+---------+----------------+------------------+---------------------------+
|    6    |   long string  |   long string    | "This is a longer string  |
|         |                |                  | for testing"              |
+---------+----------------+------------------+---------------------------+
|    7    |       NULL     |   segfault       | undefined behavior        |
|         |                |                  | (caller's responsibility) |
+---------+----------------+------------------+---------------------------+
*/
