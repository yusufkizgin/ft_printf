// yapılacak dönüşümler : c, s, d, i, u, x, X, p
#include <stdarg.h> 

static int  check_t(va_list args, char type)
{
    int i;

    i = 0;
    if (type == 'c')
        i += print_char(va_arg(args, int)); // +
    else if (type == 's')
		i += print_string(va_arg(args, char *)); // +
	else if (type == 'p')
		i += print_pointer(va_arg(args, unsigned long), 87); //hexadecimal dönüşümünde ondalık karşığını bulmak için 87 eklenir
	else if (type == 'd' || type == 'i')
		i += print_int(va_arg(args, int));
	else if (type == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (type == 'x')
		i += print_hex(va_arg(args, unsigned int), 87); //küçük harflerle hexadecimal olarak yazdırır
	else if (type == 'X')
		i += print_hex((va_arg(args, unsigned int)), 55); //büyük harflerle hexadecimal olarak yazdırır
	return (i);
}

int ft_printf(const char *string, ...)
{
    va_list     args;
    unsigned    int i;

    i = 0;
    va_start(args, string);
    while (*string != '\0')
    {
        if (*string == '%')
        {
            string++;
            if (ft_strchhr("cspiduxX", *string))
                i += check_t(args, *(string + 1));
        }
        else
            i += print_c(*string);
    }
    va_end(args);
    return (i);
}