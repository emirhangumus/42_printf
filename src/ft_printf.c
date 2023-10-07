#include "ft_printf.h"

int ft_switcher(char symbol, int i, va_list *argv)
{
    if (symbol == '%')
        i = ft_putchar_pf('%', i);
    else if (symbol == 'c')
        i = ft_putchar_pf(va_arg(*argv, int), i);
    else if (symbol == 's')
        i = ft_putstr_pf(va_arg(*argv, char *), i);
    else if (symbol == 'd' || symbol == 'i')
        i = ft_putnbr_pf((long)va_arg(*argv, int), i);
    else if (symbol == 'p')
        i = ft_putadress(va_arg(*argv, void *), i);
    else if (symbol == 'u')
        i = ft_putnbr_u_pf(va_arg(*argv, unsigned int), i);
    else if (symbol == 'x' || symbol == 'X')
        i = ft_puthex(va_arg(*argv, unsigned int), i, symbol);
    return (i);
}

int ft_printf(const char *format, ...)
{
    int             i;
    unsigned char   *s;
    va_list         argv;

    i = 0;
    s = (unsigned char *)format;
    va_start(argv, format);
    while (*s != '\0')
    {
        if (*s == '%')
        {
            s++;
            i = ft_switcher(*s, i, &argv);
        }
        else
            i = ft_putchar_pf(*s, i);
        s++;
    }
    va_end(argv);
    return (i);
}