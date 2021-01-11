#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int v[] = { 0, 2, 4, 6, 8 };
	int i = 1;
	int n = i + v[++i] /*+ v[++i]*/;
	printf("%d\n", n);
	
	system("pause");
}