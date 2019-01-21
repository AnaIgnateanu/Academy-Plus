#include "ft_printf.h"

int 		modif_precision(t_param *t)
{
	if (t->flag_zero == 1 && t->flag_minus == -1 && t->precision == -1)
		t->precision = t->width;
	return (t->precision);
}

void 		modif_width(t_param *t, int n)
{
	if (t->flag_zero == 1 && t->flag_minus == -1)
		if (t->precision == -1 && t->length == -1 && (n < 0 || t->flag_space == 1 || t->flag_plus == 1))
		{
			// printf("here\n");
			// printf("n < 0 %d\n", (long)n < 0);
			// printf("t->flag_space %d\n", t->flag_space);
			// printf("t->flag_plus %d\n", t->flag_plus);
			t->width--;
		}
}

int 		check_width(t_param *t)
{
	if (t->width > 0)
		return (t->width);
	else
		return (0);
}

int 		check_width_char(t_param *t)
{
	if (t->width > 0)
		return (t->width - 1);
	else
		return (0);
}

int 	check_justify(t_param *t)
{
	if (t->flag_minus == -1)
		if ((t->flag_zero == 1 && t->width != t->precision) || t->flag_zero == -1)
			return (1);
	return (0);
}