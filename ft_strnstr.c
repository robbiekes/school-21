#include <string.h>
#include <stdio.h>

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    if (*little == 0)
        return ((char *)big);
    while (big[i] != '\0' && i < len)
    {
        j = 0;
        while (little[j] != '\0' && big[i + j] == little[j])
        {
             if (little[j + 1] == '\0')
                return ((char *)&big[i]);
            j++;
        }
        i++;
    }
    return (0);
}

int main(void)
{
    char s1[6] = "dkfjh";
    char s2[4] = "000h";
    char *ptr;
   ptr = ft_strnstr(s1, s2, 4);
    if (ptr == 0)
        printf("%s\n", ptr);
    else
        printf("my ft = %d\n", (ptr-s1)+1);
    return (0);
}