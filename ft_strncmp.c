// #include <string.h>
// #include <stdio.h>

int ft_memcmp(const char *s1, const char *s2, size_t n)
{
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

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	return (ft_memcmp(s1, s2, n));
}

// int main(void)
// {
//     char s1[5] = "123!";
//     char s2[5] = "1235";
//     printf("my ft = %d\n", ft_strncmp(s1, s2, 6));
//     printf("orig = %d\n", strncmp(s1, s2, 6));
//     return (0);
// }