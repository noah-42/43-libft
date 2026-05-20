/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	_Overview_
		Enables callers to analyze and evaluate whether an integer (mapping
		to an ASCII table with decimal base) represents an ASCII value
		related to printable characters within the decimal ASCII table.

		Note that if 'c' -- the integer parameter -- has a value outside the
		range (e.g. negative or > 255) --> the function returns a 0 to
		represent 'false'.

		In order for the function to return 1 ('true'), the value of 'c' must
		fall within the relevant ASCII characters.
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
