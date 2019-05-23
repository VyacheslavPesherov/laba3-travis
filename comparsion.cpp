#include <string.h>


int comparsion (char *str) 
{
	char circle[7] = {'c', 'i', 'r', 'c', 'l', 'e'};
	if (strncmp(str, circle, 6) != 0)
		return 0;
	else 
		return 1;
}
