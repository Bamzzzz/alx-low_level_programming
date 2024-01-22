#include <stdio.h>
#include "main.h"

void positive_or_negative(int i)
{
	if (i > 0)
		printf("%d is a positive\n", i);
	else if (i == 0)
		printf("%d is a zero\n", i);
	else
		printf("%d is a negative\n", i);
}
