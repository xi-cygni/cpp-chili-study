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
	const char* pEnd = buf + maxSize -1; // -1 coz we need to make one space for end 0 
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

int main()
{
	char ms[] = { 'P','u','b','e','s',' ',':','(',0 };
	char ms2[] = "Pubes! :("; // "" create 0 at the end for us
	char ms3[] = "\"Pubes :( \"\n\n";
	draw(ms);
	draw(ms2);

	char c = _getch();
	_putch(c);
	draw("\n\n");

	draw("Draw some shit\n\n"); //it's still passing a pointer to read only memory 
	char inbuf[100];
	read(inbuf, 100);
	draw("\n\nYou typed: ");
	draw(inbuf);

	draw("\n\n How many pubes? ");
	char answer[69];
	read(answer, 69);
	const int pubeCounter = stringToInt(answer);
	for (int i = 0; i < pubeCounter; i++)
	{
		draw("   Pubes!  ");
	}
	
	while (!_kbhit()); //gonna loop as long as the user doesn't click sth
	return 0;
}
