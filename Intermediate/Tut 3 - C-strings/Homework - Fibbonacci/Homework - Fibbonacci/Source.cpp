#include <conio.h>

void draw(const char *s)
{
	for (; *s != 0; s++)
	{
		_putch(*s);
	}
}
void read(char* buf, int maxSize)
{
	const char* pEnd = buf + maxSize - 1; // -1 coz we need to make one space for end 0 
	for (char c = _getch(); c != 13 && buf < pEnd; c = _getch(), buf++) //13 ie enter key
	{
		*buf = c;
		_putch(c);
	}
	*buf = 0; //end of the string 
}

int stringToInt(const char* s)
{
	const char* p = s;
	for (; *p >= '0' && *p <= '9'; p++); // scan for valid digit
	p--; // to point at the last digit, meaning the less important  

	int val = 0;
	int place = 1;
	for (; p >= s; p--) //convert values and accumulate
	{
		val += (*p - '0')* place;
		place *= 10;
	}
	return val;
}

int fiboPrinter(int num)
{
	if (num < 2)
	{
		return num;
	}
	else
	{
		return fiboPrinter(num - 1) + fiboPrinter(num - 2);
	}
}
void reverseString(char * le)
{
	char* ra = le;
	while (*le != 0 )
	{
		le++;
	}
	le--;

	for(; le > ra; le--, ra++)
	{
 		const char temp = *le;
		*le = *ra; // here is sth wrong idk :((
		*ra = temp;
	}
}

void intToString(int val, char *buf, int size)
{
	char * const pEnd = buf + size;
	char* const Start = buf;
	reverseString(Start);
	while (val > 0 && buf + 1 < pEnd)
	{
		*buf = '0' + (val % 10);
		val = val / 10;
		buf++;
	}
	*buf = 0;
}

int main()
{
	char answer[100];
	/*draw("How many fibbonaci numbers you want to see? \n");
	read(answer, 1000);

	int fibNum = fiboPrinter(stringToInt(answer));*/
	//intToString(42069, answer, 100);
	reverseString("1078");

	while (!_kbhit()); //gonna loop as long as the user doesn't click sth
	return 0;
}
