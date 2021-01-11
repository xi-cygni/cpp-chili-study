#include <iostream>
#include <algorithm>
using namespace std;

void reverse(int *t, int length)
{
	for (int* j = t + length - 1; t < j; t++, j--)
	{
		swap(*t, *j);
	}
}

int main()
{
	int tab[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int size = sizeof(tab)/sizeof(int);
	reverse(tab, size);

	return 0;
}