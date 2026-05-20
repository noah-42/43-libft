/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = get_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

/*
	_Pseudo code_
		Helper: get_len(n)
		1. If 'n' is 0 or negative --> start count at 1
			(reserve space for '0' or '-' sign)
		2. While 'n' is not 0 --> divide 'n' by 10 and increment count
		3. Return the count

		Main: ft_itoa(n)
		1. Cast 'n' to 'long' ('nb') to handle INT_MIN safely
		2. Get the string length via get_len
		3. Allocate 'len + 1' bytes via ft_calloc
		4. If allocation fails --> return NULL
		5. If 'nb' is 0 --> set str[0] = '0'
		6. If 'nb' is negative --> set str[0] = '-'
			and negate 'nb' to make it positive
		7. While 'nb' > 0:
			- Write the last digit ('nb % 10' + '0')
				into 'str[--len]' (filling from the end)
			- Divide 'nb' by 10 to drop the last digit
		8. Return 'str'
*/

/*
+---------+----------------+----------------+---------------------------+
|   Ex.   |       n        |     result     |          notes            |
+---------+----------------+----------------+---------------------------+
|    1    |       0        |     "0"        | zero                      |
+---------+----------------+----------------+---------------------------+
|    2    |      42        |     "42"       | positive number           |
+---------+----------------+----------------+---------------------------+
|    3    |      -42       |     "-42"      | negative number           |
+---------+----------------+----------------+---------------------------+
|    4    |       7        |     "7"        | single digit              |
+---------+----------------+----------------+---------------------------+
|    5    |      -3        |     "-3"       | single negative digit     |
+---------+----------------+----------------+---------------------------+
|    6    |  2147483647    | "2147483647"   | INT_MAX                   |
+---------+----------------+----------------+---------------------------+
|    7    | -2147483648    | "-2147483648"  | INT_MIN (needs long cast) |
+---------+----------------+----------------+---------------------------+
|    8    |      -1        |     "-1"       | small negative            |
+---------+----------------+----------------+---------------------------+
|    9    |     1000       |    "1000"      | multi-digit with zeros    |
+---------+----------------+----------------+---------------------------+
|   10    |  malloc fails  |     NULL       | allocation failure        |
+---------+----------------+----------------+---------------------------+
*/
