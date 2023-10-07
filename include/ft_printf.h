#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_printf(const char *format, ...);
int ft_putchar_pf(char c, int i);
int ft_putstr_pf(char *s, int i);
int ft_putnbr_pf(long n, int i);
int ft_putnbr_u_pf(unsigned int n, int i);

// adress functions
int numDigits(int num);
void intToHexStr(int num, char* buffer);
int ft_putadress(void *p, int i);

// hex functions
int ft_puthex(unsigned int x, int i, char format);

#endif