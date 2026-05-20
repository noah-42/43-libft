/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	_Overview_
		Searches for the last occurrence of a character, `c` in a string,
		`s` and returns a pointer to it.

		This function is ONLY meant to be used for strings.

	_Return value_
		Returns the address in memory (pointer) for the last occurence of a
		given character 'c' in string 's'.

		For example, in the 's' for "Hello", with the 'c' of "l", the
		function should return the address for the last "l" (e.g. after
		"l" and before "o").

		If 'c' is '\0' then the function should return the address for then
		null terminator.

		If 'c' cannot be found, the function returns NULL.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (int)ft_strlen(s);
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*
_Pseudo code_
	1. Get the length of 's' via ft_strlen
	2. Start from the end of 's' (at the null terminator position)
	3. Loop backwards through 's':
		- If 's[i]' == 'c' --> return address of 's[i]'
		- Decrement 'i'
	4. If 'c' was not found --> return NULL

	Note: by starting at the null terminator position, this naturally
	handles the case where 'c' is '\0' -- it will match immediately
	on the first iteration.

*/
