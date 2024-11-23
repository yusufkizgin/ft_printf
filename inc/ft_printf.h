#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "./libft.h"

int		ft_printf(const char *input, ...);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_string(char *s);
int		ft_print_int(int n);
int		ft_print_char(char c);
int		ft_print_hex(unsigned int value, int asc);

#endif