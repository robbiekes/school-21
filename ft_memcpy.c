#include <string.h>
#include <stdio.h>

void *ft_memcpy(void *dest, void *src, size_t n)
{
    char *copy_to;
    copy_to = dest;
    char *copy_from;
    copy_from = src;
    int i;
    i = 0;
    if (!(copy_to == NULL) && !(copy_from == NULL))
    {
        while(copy_from[i] != '\0' && copy_from[i] != '\0' && n > 0)
        {
            copy_to[i] = copy_from[i];
            i++;
            n--;
        }
    }
    copy_to[i] = '\0';
    return (dest);
}

int main(void)
{
    char dest[10] = "dfdkjdkfj";
    dest[10] = '\0';
    char src[11] = "iiei000000";
    src[11] = '\0';
    ft_memcpy(dest, src, 11);
    printf("%s", dest);
    return (0);
}
