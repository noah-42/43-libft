/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	_Overview_
		Allocates sufficient memory for a copy of the string 's', does the
		copy, and returns a pointer to it.

	_Safety Profile_
		Checks whether the allocation of memory was succesful.

	_Return value_
		- Returns a pointer to the copy of the 's' --> 'dup'.
		  --> this pointer may subsequently be used as an argument for free()
				to the program or function that calls ft_strdup

		- Returns NULL if there is insufficient memory (aka allocation failure
		check).
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, len + 1);
	return (dup);
}
