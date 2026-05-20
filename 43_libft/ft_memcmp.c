/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	_Overview_
	Compares two blocks of memory ('s1' and 's2') up to 'n' bytes and stops
	when it finds a difference.

	It stops upon:
	- reaching 'n' bytes
	- finding a difference

	_Return value_
		- A positive value if 's1' > 's2'
		- A negative value if 's1' < 's2'
		- 0 if both blocks are identical up to 'n' bytes

		_Use case_
		Useful for comparing various data types incl. binary files, images,
		structs, etc.

		Unlike ft_strncmp -- ft_memcmp does NOT stop at a null terminator.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((int)str1[i] - (int)str2[i]);
		i++;
	}
	return (0);
}

/*
	_Pseudo code_
	1. Cast 's1' and 's2' to 'unsigned char *'
	2. Loop through both blocks up to 'n' bytes:
		- If 'str1[i]' != 'str2[i]' --> return the difference
			('str1[i]' - 'str2[i]')
		- Otherwise, increment 'i'
	3. If all 'n' bytes are equal --> return 0
*/
