#include <stdio.h>
#include <string.h>

// # define ft_bzero(b,len) (ft_memset((b), '\0', (len)), (void) 0)
// void *ft_memset(void *str, int x, size_t n)
// {
//     unsigned char *arr;
//     arr = str;
//     while(n)
//     {
//         *arr++ = x;
//         n--;
//     }
//     return (str);
// }

void ft_bzero(void *str, size_t bytes)
{
    char *arr;
    arr = (char *)str;
    while (bytes)
    {
        *arr++ = 0;
        bytes--;
    }
}

int main(void)
{
    char tab[100];
    memset(tab, 'A', 100);
    ft_bzero(tab, 0);
    printf("ans -> %d\n", tab[0] == 'A');
    
    ft_bzero(tab, 42);
    int i = 0;
    for (; i < 100 && tab[i] == 0; ++i)
        ;
    printf("ans -> %d\n", i == 42 && tab[42] == 'A'); 

    memset(tab, 'A', 100);
    tab[0] = 0;
    ft_bzero(tab, 42);
    i = 0;
    for (; i < 100 && tab[i] == 0; ++i)
        ;
    printf("ans -> %d\n", i == 42);
    return (0);
}