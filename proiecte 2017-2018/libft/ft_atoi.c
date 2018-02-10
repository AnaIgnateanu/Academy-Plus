#include "libft.h"

/*Converts a character string to an integer value. The input string is a sequence of characters
that can be interpreted as a numerical value. The function stops reading the input string at
the first character it cannot recognie as part of a number.
*/


int 	ft_atoi(const char *str)
{
	int 	sign;
	int		n;

	sign = 1;
	n = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13) )
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + sign * (*str - '0');
		str++;
	}
	return (n);
}