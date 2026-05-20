/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
	_Overview_
		Copies a string from a source 'src' to a destination 'dst' —>
		safely —> meaning if there is any mismatch the program will not
		crash:
			- always null-terminates
		 	- never overflows
			- returns 'strlen(src)' so one can detect truncation.

	_Context_
		This function is only meant to be used for strings.

	_Parameter(s)_
		The 'dst_size' parameter is the size of the 'dst' string.

	_Return value_
		The return value is the size of the string that the function TRIES
		to create (i.e. the number of characters in the 'src' parameter).

		As mentioned, the caller of the function can use this to know if the copy
		of the string was truncated.

	_Risks_
	- truncated copy from 'src' to 'dst'

*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dst_size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (dst_size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/******************************************************************


__ Scenarios & cases __
+---------+---------+----------+----------+--------+-------------------------+
| Example |   src   | dst_size |   dst    | return |       Truncated?        |
|         |         |          |  after   |(size_t)|                         |
+---------+---------+----------+----------+--------+-------------------------+
|    1    | "hello" |    20    | "hello"  |   5    |   No (5 < 20)           |
+---------+---------+----------+----------+--------+-------------------------+
|    2    | "hello" |     4    |  "hel"   |   5    |   Yes (5 >= 4)          |
+---------+---------+----------+----------+--------+-------------------------+
|    3    | "hello" |     0    | unchanged|   5    |No, nothing copied over  |
+---------+---------+----------+----------+--------+-------------------------+
|    4    | "hello" |     1    |    ""    |   5    |Yes (5 >= 1, null only)  |
+---------+---------+----------+----------+--------+-------------------------+
|    5    |    ""   |    10    |    ""    |   0    |   No (src is empty)     |
+---------+---------+----------+----------+--------+-------------------------+
|    6    | "hello" |     6    | "hello"  |   5    |   No (5 < 6, exact fit) |
+---------+---------+----------+----------+--------+-------------------------+


__ Pseudo code & notes __
	1. If 'dst_size' is 0 --> there is no room to copy so return the
		length of 'src'
	2. While 'src[i]' is not '\0' AND there is enough space left
		('i < dst_size - 1')
	3. Copy characters from 'src' to 'dst' until:
		- 'src[i]' is the null terminator
		- OR we're at one byte before the end of 'dst'
	4. Write the null terminator to 'dst[i]'
	5. Return the length of 'src' (calculated via ft_strlen)

*******************************************************************/
