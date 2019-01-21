#include "ft_printf.h"

int 		is_flag(char x)
{
	return (x == '#' || x == '0' || x == '-' || x == '+' || x == ' ');
}

int 		is_length_modif(char x)
{
	return (x == 'h' || x == 'l' || x == 'j' || x == 'z' || x == 'L');
}

int 		is_num_specif(char x)
{
	return (INT_SPECIF(x) || OCT_SPECIF(x) || U_INT_SPECIF(x)
		|| HEX_SPECIF(x) || C_HEX_SPECIF(x) || L_FLOAT_SPECIF(x) || U_FLOAT_SPECIF(x) || SCI_SPECIF(x) || L_SCI_SPECIF(x)
		|| FE_SPECIF(x) || L_FE_SPECIF(x));
}
int 		is_long_specif(char x)
{
	return (LONG_SPECIF(x) || L_OCT_SPECIF(x) || U_LONG_SPECIF(x) || PTR_SPECIF(x));
}
int 		is_char_specif(char x)
{
	return (CHAR_SPECIF(x) || STR_SPECIF(x) || W_CHAR_SPECIF(x) || W_STR_SPECIF(x) || N_SPECIF(x));
}

