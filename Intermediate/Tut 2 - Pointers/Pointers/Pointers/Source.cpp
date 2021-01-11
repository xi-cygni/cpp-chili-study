int main()
{
	int n = 5;
	int *p;
	p = &n; // this is how we make our pinter to point to a certain variable, & is address of operator
	*p = *p + 4; // if u want to get at what pointer points

	int *ptr;
	ptr = nullptr; // it says that this pointer isn't pointing to any shit right now

	// you can assign 1 pointer to another if their types are compatible 

	return 0;
}