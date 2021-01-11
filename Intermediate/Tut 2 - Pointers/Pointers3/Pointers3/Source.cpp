class Foo
{
	public:
	int bar;
	int baz;
	char fizz;
};

int main()
{
	Foo myFoo;
	Foo* pFoo = &myFoo;
	int* pInt = &myFoo.baz;
	char* pChar = &(*pFoo).fizz; //() dereferencing pFoo, paranthesis coz . operator is working on dereferenced object
								// the same as &pFoo->fizz dereference the pointer and access the member fizz
								// this is basically the same as &myFoo.fizz coz we dereference pFoo so it goes to value od myFoo!!!
}