#include <stdio.h>
#include <unistd.h>

int ft_putstr_fd(int fd, char *str)
{
    static int  count1 = 0;
    static int  count2 = 0;
    int i;

    i = 0;
    while (str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
    if (fd == 2)
    {
        count2++;
        return (count2);
    }
    count1++;
    return (count1);
}

int main(void)
{
    printf(" %d\n", ft_putstr_fd(1, "123"));
    printf(" %d\n", ft_putstr_fd(1, "123"));
    printf(" %d\n", ft_putstr_fd(2, "123"));
    printf(" %d\n", ft_putstr_fd(1, "123"));
    printf(" %d\n", ft_putstr_fd(2, "123"));
    printf(" %d\n", ft_putstr_fd(1, "123"));
    return (0);
}