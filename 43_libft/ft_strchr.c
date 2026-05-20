/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                        +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	_Overview_
		Searches for the first occurrence of a character, `c` in a string,
		`s` and returns a pointer to it.

		This function is ONLY meant to be used for strings.

	_Return value_
		Returns the address in memory (pointer) for the first occurence of a
		given character 'c' in string 's'.

		For example, in the 's' for "Hello", with the 'c' of "l", the
		function should return the address for the first "l" (e.g.
		after "e").

		If 'c' is '\0' then the function should return the address for then
		null terminator.

		If 'c' cannot be found, the function returns NULL.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*
	_Pseudo code_
	1. Loop through 's' character by character:
		- If 's[i]' == 'c' --> return address of 's[i]'
	2. After the loop, check if 'c' is '\0':
		- If yes --> return address of the null terminator
	3. If 'c' was not found --> return NULL
*/
