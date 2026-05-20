/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norobins <norobins@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:44:51 by norobins          #+#    #+#             */
/*   Updated: 2026/05/10 22:05:13 by norobins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	_Overview_
		Searches a block of memory, 'blk', up to 'n' bytes for the first
		occurence of a specific byte 'c'.

	_Return value_
		- the memory address of the byte 'c' if it finds it; otherwise
		- NULL

	_Use case_
		This is useful for all data types but ft_strchr is customized better
		to handle strings as it handles '\0' whereas ft_memchr does not
		explicitly check.

		ft_memchr would treat '\0' as any other byte
		whereas ft_strchr would stop upon reaching the null terminator.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*blk;
	unsigned char	t;
	size_t			i;

	blk = (unsigned char *)s;
	t = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (blk[i] == t)
			return ((void *)(blk + i));
		i++;
	}
	return (NULL);
}
