#include <iostream>

using namespace std;

int main()
{
	int a = 21;
	int *p = &a;
	int **dp = &p;

	cout << "&a = " << &a << endl;
	cout << "*p = " << *p << endl;
	cout << "&p = " << &p <<endl;
	cout << "*dp = "<< *dp << endl;
	cout << "&dp = "<< &dp << endl;
	cout << "**dp = "<< **dp <<endl;

	system("pause");

}