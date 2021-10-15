#include <stdio.h>
#include <string.h>

int main(void)
{
	char set1[] = "0123456789";
	char set2[] = "0123456789";
	printf("move: %s\n", (char*) memmove(&set1[3], &set1[1], 7));
	printf("cpy : %s\n", (char *)memcpy(&set2[3], &set2[1], 7));
	return (0);
}
