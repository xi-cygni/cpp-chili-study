void swap(int *a, int *b) //swap( &a, &b)          to samooo
{
	int temp = *a;        // int temp = a;
	*a = *b;              // a = b;
	*b = temp;            // b = temp;
}
int main()
{
	int m = 7;
	int n = 2;
	swap(&m, &n); //swap(m,n)

	return 0;
}