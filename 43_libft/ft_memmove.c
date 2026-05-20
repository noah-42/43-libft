/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+         +:+         */
/*   By: noah     <noah-   @student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:06:43 by noah-42           #+#    #+#             */
/*   Updated: 2026/05/17 00:22:34 by noah-42           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

/*
	_Overview_
		Unlike ft_memcpy, which also copies bytes from a source to a
		to a destination -- this function ensures that there is no risk of
		overlap between the destination and the source.

		If dst comes before src, function copies from beginning to end.

		Otherwise, if dst > src (and there is at least one byte), it copies
		memory from the end to the beginning.

		_NULL guard_
		No use of NULL guard in this function because the original function
		is intentionally designed to allow for "undefined behavior" -- including
		overwriting data and crashing.

		It is the caller's responsibility to use this function safely.

		_Risks_
		- Overwriting data
		- Crash (segfault)
		- Appears to work fine with hidden bugs

		EXAMPLE
		if (n == 0 || (dst == NULL && src == NULL))
			return (dst);
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				nb;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	nb = n;
	if (d < s)
		return (ft_memcpy(dst, src, nb));
	while (nb > 0)
	{
		nb--;
		d[nb] = s[nb];
	}
	return (dst);
}

/*
	PSEUDO
	1. To avoid potential overlap, check if 'dst' is before 'src'
	2. If so, copy 'n' bytes from beginning to end

	Otherwise
	3. copy 'n' bytes from last byte first byte
*/
