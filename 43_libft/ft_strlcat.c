/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                        +:+         +:+     */
/*   By: noah     <noah-   @student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	_Overview_
		Appends a string 'src' to another string 'dst' and guarantees a '\0'
		at the end.

	_Context_
		This function is only meant to be used for strings.

	_Parameter(s)_
		'dst_size' is the full size of the destination buffer (in bytes) --
		which must be pre-allocated before the function is called.

	_Return value_
		'size_t' is for the total length of the new string that
		the function TRIES to create (initial length of 'dst' + the
		length of 'src').

		Note that this return value does not include the null terminator
		(even though the function guarantees a '\0').

		For example, "hello world" is 11 characters + '\0'.

	_Risks_
	- truncated append from 'src' to 'dst'

*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < dst_size && dst[dst_len] != '\0')
		dst_len++;
	src_len = ft_strlen(src);
	if (dst_len == dst_size)
		return (dst_size + src_len);
	i = 0;
	while (src[i] != '\0' && (dst_len + i + 1) < dst_size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/******************************************************************


__ Scenarios & cases __
/*
+---------+----------+----------+----------+-------------+--------+--------------------------+
|   Ex.   |   dst    |   src    |   dst_   |     dst     | return |       Truncated?         |
|         |          |          |   size   |    after    |(size_t)|                          |
+---------+----------+----------+----------+-------------+--------+--------------------------+
|    1    | "hello"  | " world" |    20    |"hello world"|   11   |    No (11 < 20)          |
+---------+----------+----------+----------+-------------+--------+--------------------------+
|    2    | "hello"  | " world" |    10    | "hello wor" |   11   |    Yes (11 >= 10)        |
+---------+----------+----------+----------+-------------+--------+--------------------------+
|    3    | "hello"  | " world" |    5     |   "hello"   |   11   |Yes (dstlen == dst_size)  |
+---------+----------+----------+----------+-------------+--------+--------------------------+
|    4    | "hello"  | " world" |    0     |   "hello"   |   11   | Yes (dst_size == 0)      |
+---------+----------+----------+----------+-------------+--------+--------------------------+
|    5    | "hello"  |    ""    |    10    |   "hello"   |    5   |    No (src is empty)     |
+---------+----------+----------+----------+-------------+--------+--------------------------+
|    6    |    ""    | "hello"  |    10    |   "hello"   |    5   |    No (5 < 10)           |
+---------+----------+----------+----------+-------------+--------+--------------------------+
|    7    | "hello"  | " world" |    12    |"hello world"|   11   | No (11 < 12, exact fit)  |
+---------+----------+----------+----------+-------------+--------+--------------------------+
*/

/*
	PSEUDO CODE
	1. Find the length of 'dst' by walking through it --
		but stop if we reach 'dst_size' (safety boundary)
	2. Get the length of 'src' via ft_strlen
	3. If 'dst_len' == 'dst_size' --> 'dst' is already full,
		return 'dst_size + src_len' (nothing to append)
	4. Append characters from 'src' to the end of 'dst' while
		there is room ('dst_len + i + 1 < dst_size')
	5. Write the null terminator to 'dst[dst_len + i]'
	6. Return 'dst_len + src_len' (the total length tried to create)
*/
