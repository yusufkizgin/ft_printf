#include "ft_printf.h"

int ft_print_s(char *s)
{
    unsigned int i;

    i = 0;
    if (!s)
    {
        ft_putstr_fd("(null)", 1);
        return (6);
    }
    while (s[i])
        i++;
    ft_putstr_fd(s, 1);
    return (i);
}