/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah     <noah-   @student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:23:00 by by noah-42        #+#    #+#             */
/*   Updated: 2026/05/17 18:17:04 by norobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	_Overview_
		Enables callers to assign a 0 (zero) to up to a given # of bytes
		in a contiguous block of memory.

		ft_bzero is about bytes --in a contiguous block of memory, not
		necessarily characters in a string.

	_NULL guard_
		No use of NULL guard in this function because the original function
		is intentionally designed to allow for "undefined behavior" --
		including crashing. It is the caller's responsibility to use this
		function safely.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
