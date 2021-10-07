#include <string.h>
#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *str)
{
    size_t i;
    i = 0;
    
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int main(void)
{
    char arr[6] = "tooth";
    int len = ft_strlen(arr);
    return (0);
}