#include <stdio.h>
#include <unistd.h>

int ft_putstr(char *str)
{
    static int  count = 0;
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    count++;
    return (count);
}

int main(void)
{
    printf(" %d\n", ft_putstr("123"));
    printf(" %d\n", ft_putstr("123"));
    printf(" %d\n", ft_putstr("123"));
    return (0);
}
