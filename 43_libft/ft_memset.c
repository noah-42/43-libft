/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah     <noah-   @student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*	_Overview_
		Enables callers to assign a specific byte value up to a given # of
		bytes in a block.

		ft_memset is about bytes --in a contiguous block of memory, not
		necessarily characters in a string.

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

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*blk;

	i = 0;
	blk = (unsigned char *)s;
	while (i < n)
	{
		blk[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
