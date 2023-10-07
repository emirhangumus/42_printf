#include "ft_printf.h"

int main()
{
    char *str = "Emirhan";
    char c = 'T';
    int sayi = 12381235;
    int negatif_sayi = -12313;

    int o = printf("O: Merhaba dunya %s %c %d %i %p %u %x %X\n", str, c, sayi, negatif_sayi, str, sayi, sayi, sayi);
    int m = ft_printf("M: Merhaba dunya %s %c %d %i %p %u %x %X\n", str, c, sayi, negatif_sayi, str, sayi, sayi, sayi);

    printf("o: %d, m: %d\n", o, m);

    return 0;
}