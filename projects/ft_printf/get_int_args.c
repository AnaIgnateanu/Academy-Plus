#include "ft_printf.h"

intmax_t	get_i(char c, va_list *list, int length_modif)
{
	if (length_modif == L || LONG_SPECIF(c))
		return (va_arg(*list, long));
	else if (length_modif == HH)
		return ((char)va_arg(*list, int));
	else if (length_modif == H)
		return ((short)va_arg(*list, int));
	else if (length_modif == LL)
		return (va_arg(*list, long long));
	else if (length_modif == J)
		return (va_arg(*list, intmax_t));
	else if (length_modif == Z)
		return (va_arg(*list, ssize_t));
	return (va_arg(*list, int));
}

uintmax_t	get_u(char c, va_list *list, int length_modif)
{
	if (length_modif == L || U_LONG_SPECIF(c) || L_OCT_SPECIF(c))
		return (va_arg(*list, unsigned long));
	else if (length_modif == HH)
		return ((unsigned char)va_arg(*list, unsigned int));
	else if (length_modif == H)
		return ((unsigned short)va_arg(*list, unsigned int));
	else if (length_modif == LL)
		return (va_arg(*list, unsigned long long));
	else if (length_modif == J)
		return (va_arg(*list, uintmax_t));
	else if (length_modif == Z)
		return (va_arg(*list, size_t));
	else if (PTR_SPECIF(c))
		return ((unsigned long)va_arg(*list, void *));
	return (va_arg(*list, unsigned int));
}