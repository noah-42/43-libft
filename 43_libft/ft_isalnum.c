/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah     <noah-   @student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	_Overview_
		Enables callers to analyze and evaluate whether an integer (mapping
		to. an ASCII table with decimal base) represents an alphabetical
		character or an integer between 0 and 9.

		Note that if 'c' -- the integer parameter -- has a value outside
		the range (e.g. negative or > 255) --> the function returns a 0 to
		represent 'false'.

		In order for the function to return 1 ('true'), the value of 'c'
		must fall within the relevant ASCII characters.
*/

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
