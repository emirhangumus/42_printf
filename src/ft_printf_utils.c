#include "libft.h"

int ft_putchar_pf(char c, int i)
{
    write(1, &c, 1);
    return (++i);
}

int ft_putstr_pf(char *s, int i)
{
    int x;
    
    x = 0;
    while (s[x])
    {
        i = ft_putchar_pf(s[x], i);
        x++;
    }
    return (i);
}

int ft_putnbr_pf(long n, int i)
{
    if (n < 0)
    {
        i = ft_putchar_pf('-', i);
        n *= -1;
    }
    if (n > 9)
    {
        i = ft_putnbr_pf(n / 10, i);
        i = ft_putnbr_pf(n % 10, i);
    }
    else
        i = ft_putchar_pf(n + '0', i);
    return (i);
}

int ft_putnbr_u_pf(unsigned int n, int i)
{
    if (n > 9)
    {
        i = ft_putnbr_u_pf(n / 10, i);
        i = ft_putnbr_u_pf(n % 10, i);
    }
    else
        i = ft_putchar_pf(n + '0', i);
    return (i);
}