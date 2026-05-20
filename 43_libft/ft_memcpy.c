/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+         +:+         */
/*   By: noah     <noah-   @student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:02:48 by noah-42           #+#    #+#             */
/*   Updated: 2026/05/13 16:01:19 by by noah-42        #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

/*	_Overview_
		Enables callers to copy a specific # of continuous bytes from one
		block of memory to another.

	_NULL guard_
		No use of NULL guard in this function because the original function
		is intentionally designed to allow for "undefined behavior" --
		including crashing.

		It is the caller's responsibility to use this function safely.

	_Risks_
		- Crashing (segfault)
		- Overwriting data
		- Creating hidden bugs

*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
