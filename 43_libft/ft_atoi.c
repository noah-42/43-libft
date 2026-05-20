/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-42  <@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	_Overview_
		Converts the first sequence of characters via string 's' -- which is
		an ASCII representation of an integer into the appropriate
 	'int'.

	_Return value_
		The appropriate 'int'

	_Undefined behavior_
		Note that this function has undefined behavior on overflow
		(e.g. 2147483648) on a 32-bit int.

		This is in accordance with atoi in Standard C.
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

/*
	PSEUDO CODE
	1. Set 'res' to 0 and 'sign' to 1
	2. Skip whitespace characters (' ', tab, newline, etc.)
	3. If the next character is '+' or '-':
		- If '-' --> set 'sign' to -1
		- Move to the next character
	4. While the current character is a digit ('0'-'9'):
		- Multiply 'res' by 10 and add the digit value
		- Move to the next character
	5. Return 'res * sign'
*/

/*
+---------+-----------------+---------+---------------------------+
|   Ex.   |       s         | result  |          notes            |
+---------+-----------------+---------+---------------------------+
|    1    |     "42"        |   42    | basic positive            |
+---------+-----------------+---------+---------------------------+
|    2    |     "-42"       |  -42    | basic negative            |
+---------+-----------------+---------+---------------------------+
|    3    |      "0"        |    0    | zero                      |
+---------+-----------------+---------+---------------------------+
|    4    |    "   42"      |   42    | leading spaces            |
+---------+-----------------+---------+---------------------------+
|    5    |   "\t\n\v42"    |   42    | leading whitespace        |
+---------+-----------------+---------+---------------------------+
|    6    |     "+42"       |   42    | explicit plus sign        |
+---------+-----------------+---------+---------------------------+
|    7    |    "42abc"      |   42    | trailing non-digits       |
+---------+-----------------+---------+---------------------------+
|    8    |     "abc"       |    0    | no digits at all          |
+---------+-----------------+---------+---------------------------+
|    9    |   "   abc"      |    0    | spaces then non-digit     |
+---------+-----------------+---------+---------------------------+
|   10    |    "+-42"       |    0    | multiple signs            |
+---------+-----------------+---------+---------------------------+
|   11    |      ""         |    0    | empty string              |
+---------+-----------------+---------+---------------------------+
|   12    | "2147483647"    |  INT_MAX| max int value             |
+---------+-----------------+---------+---------------------------+
|   13    | "-2147483648"   |  INT_MIN| min int value             |
+---------+-----------------+---------+---------------------------+
|   14    | "2147483648"    |  undef. | overflow (undefined       |
|         |                 |         | behavior, matches atoi)   |
+---------+-----------------+---------+---------------------------+
*/
