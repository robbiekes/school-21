int ft_atoi(char *str)
{
    int sign = 1;
    int num = 0;
    int  i = 0;
    while(str[i] == ' ' || str[i] == '\t'|| str[i] == '\v' || str[i] == '\f' || 
        str[i] == '\n' || str[i] == '\r')
            i++;
    while(str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-') 
            sign = -sign;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    return num*sign;
}