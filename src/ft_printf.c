// yapılacak dönüşümler : c, s, d, i, u, x, X, p
#include <stdarg.h> 

static int  check_t(const char *str, void *arg)
{
    int i;

    i = 0;
    if (*str == 'c')
        i += print_char((int)arg); // +
    else if (*str == 's')
		i += print_string((char *)arg); // +
	else if (*str == 'p')
		i += print_pointer((unsigned long)arg, 87); //hexadecimal dönüşümünde ondalık karşığını bulmak için 87 eklenir
	else if (*str == 'd' || *str == 'i')
		i += print_int((int)arg);
	else if (*str == 'u')
		i += print_unsigned((unsigned int)arg);
	else if (*str == 'x')
		i += print_hex((unsigned int)arg, 87); //küçük harflerle hexadecimal olarak yazdırır
	else if (*str == 'X')
		i += print_hex((unsigned int)arg, 55); //büyük harflerle hexadecimal olarak yazdırır
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
                i += check_t(string, va_arg(args, void *));
        }
        else
            i += print_c(*string);
    }
    va_end(args);
    return (i);
}