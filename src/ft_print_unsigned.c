#include <unistd.h>

static void print(unsigned int nb)
{
    if (nb > 9)
        print(nb / 10);
    ft_putchar_fd(nb % 10 + '0', 1);
}

int ft_print_unsigned(unsigned int nb)
{
    unsigned int    i;

    print(nb);
    i = 1;
    while (nb > 9)
    {
        nb = nb / 10;
        i++;
    }
    return (i);
}