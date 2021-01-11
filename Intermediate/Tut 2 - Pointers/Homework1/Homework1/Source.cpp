#include <iostream>

using namespace std;

int sum(int *tab, int length)
{
	int result = 0;
	
	for (int i = 0; i < length; i++)
	{
		result += tab[i];
	}
	return result;
}


int main()
{
	int t[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int size = sizeof(t)/sizeof(int);

	sum(t, size);

	return 0;
}