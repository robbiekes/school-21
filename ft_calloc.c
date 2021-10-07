#include <stdio.h>
#include <stdlib.h>

void ft_bzero(char *str, int bytes)
{
    char *arr;
    arr = str;
    while (bytes)
    {
        *arr++ = 0;
        bytes--;
    }
}

void *calloc(size_t nmemb, size_t size)
{
    void *arr;
    arr = (void *)malloc(size * nmemb);
    if (arr == NULL)
        return (0);
    else
    {
        ft_bzero(arr, nmemb);
        return (arr);
    }
}

int main(void)
{
    char *array;
    array = (char *)calloc(5, sizeof(char));
    array = "hello";
    printf("%s\n", array);
    return (0);
}