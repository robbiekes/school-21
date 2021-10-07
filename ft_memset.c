#include <string.h>
#include <stdio.h>

void *ft_memset(void *str, int x, size_t n)
{
    unsigned char *arr;
    arr = (unsigned char *)str;
    while(n)
    {
        *arr++ = (unsigned char)x;
        n--;
    }
    return (str);
}

int main(void)
{
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    ft_memset(arr+4, 0, 4*sizeof(int));
    int n = 0;
    while(n < 9)
    {
        printf("%d", arr[n]);
        n++;
    }
    printf("!");
    return (0);
}