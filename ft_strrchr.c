#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str)
{
    size_t i;
    i = 0;
    
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

char *ft_strrchr(const char *s, int c)
{
    char *arr;
    arr = (char *) s;
    int len = ft_strlen(arr);
    if (arr == NULL)
        return NULL;
    while(len >= 0)
    {
        if (arr[len] == (char)c)
            return &arr[len];
        len--;
    }
    return NULL;
}

int main(void)
{
    char arr[8] = "3473276";
    arr[8] = '\0';
    char *ptr;
    ptr = ft_strrchr(arr, '\0');
    if (ptr == NULL)
        printf("my ft = %s\n", ptr);
    else
        printf("my ft = %d\n", (ptr-arr)+1);
    return (0);
}