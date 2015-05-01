#include "VectorT.h"
#include <iostream>

void main()
{
	int a[5] = { 0, 1, 2, 3, 4};

	for(int last = 5,first = 0; last != first;)
	{
		a[--last] = -1;
	}
}