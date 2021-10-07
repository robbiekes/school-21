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

char *ft_strchr(const char *s, int c)
{
    char *arr;
    arr = (char *)s;
    int i;
    i = 0;
    if (arr == NULL)
        return NULL;
    while(arr[i])
    {
        if (arr[i] == (char)c)
            return &arr[i];
        i++;
    }
    return NULL;
}

int main(void)
{
    char arr[8] = "3473276";
    arr[8] = '\0';
    char *ptr;
    ptr = strchr(arr, '\0');
    if (ptr == NULL)
        printf("my ft = %s\n", ptr);
    else
        printf("my ft = %d\n", (ptr-arr)+1);
    return (0);
}