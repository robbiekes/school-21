#include <string.h>
#include <stdio.h>

int ft_memcmp(const char *s1, const char *s2, size_t n)
{
    // unsigned const char *arr1; // другой вариант приведения в тип unsigned char
    // unsigned const char *arr2;

    // arr1 = (unsigned const char*) s1;
    // arr2 = (unsigned const char*) s2;
    size_t i;
    i = 0;
    while (i <= n)
    {
        if (s1[i] != s2[i])
            return ((int)(unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}

int main(void)
{
    char s1[5] = "1234";
    char s2[5] = "1235";
    printf("my ft memcmp = %d\n", ft_memcmp(s1, s2, 5));
    printf("orig = %d\n", memcmp(s1, s2, 5));
    return (0);
}