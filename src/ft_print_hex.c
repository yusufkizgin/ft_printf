static char *create_space(unsigned long value, int *strlen)
{
    int				i;
	unsigned long	temp;
	char			*str;

    temp = value;
    i = 0;
    while (temp != 0)
    {
        temp = temp / 16;
        i++;
    }
    str = calloc(i + 1, sizeof(char));
    *strlen = i - 1;
    return (str);
}    

int ft_print_pointer(unsigned long value, int asc)
{
    unsigned long   temp;
    int             len;
    int             *iptr;
    char            *space;

    iptr = &len;
    temp = value;
    space = create_space(temp, iptr);
    if (!space)
    {
        return (0);
    }
    while (temp != 0 && len-- >= 0)
    {
        if (temp % 16 < 10)
            space[len] = temp % 16 + '0';
        else
            space[len] = temp % 16 + asc;
        temp = temp / 16;
    }
    len = print_string(space);;
    free(space);
    if (value == 0)
        print_string("0");
    return (len);
}
