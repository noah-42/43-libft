/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	_Overview_
		Allocates 'nmemb' blocks of memory, each of 'size' bytes, and
		initializes every byte to zero.

	_Return value_
		If successful, returns the pointer to the first byte of memory of a
		block of memory via ft_memset (which ft_memset initializes).

		If the allocation fails (i.e. not enough memory available); returns
		NULL.

	_Note from 42 subject_
		Depending on your current operating system, the ’calloc’ function’s
		behavior may differ from its man page description.

		You must follow this rule: If nmemb or size is 0, then calloc()
		returns a unique pointer value that can be successfully passed
		to free().
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > ((size_t)-1) / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}
