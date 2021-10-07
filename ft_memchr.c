#include <string.h>
void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned const char *arr;
    int i = 0;
    arr = (unsigned const char *)s;
    int len = ft_strlen(arr)-1;
    if (arr == NULL)
        return NULL;
    while(n)
    {
        if (arr[i] == (unsigned char)c)
            return &arr[len];
        n--;
    }
    return NULL;
}