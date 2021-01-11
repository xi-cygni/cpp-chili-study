#include <conio.h>
#include <fstream> //filestram

namespace aguszka
{
	void printWidth(const char *s, int w)
	{
		int n = 0;
		for (; *s != 0; s++)
		{
			_putch(*s);
			n++;
		}
		for (; n < w; n++)
		{
			_putch(' ');
		}
	}
	void print(const char* s)
	{
		for (; *s != 0; s++)
		{
			_putch(*s);
		}
	}

	void read(char* buf, int maxSize)
	{
		const char* const pEnd = buf + maxSize;
		for (char c = _getch(); c != 13 && (buf + 1 < pEnd); c = _getch(), buf++)
		{
			_putch(c);
			*buf = c;
		}
		*buf = 0;
	}

	int str2int(const char* s)
	{
		// scan to start point
		const char* p = s;
		for (; *p >= '0' && *p <= '9'; p++);
		p--;

		int val = 0;
		int place = 1;
		// convert place values and accumulate
		for (; p >= s; p--)
		{
			val += (*p - '0') * place;
			place *= 10;
		}

		return val;
	}

	int fib(int n)
	{
		if (n < 2)
		{
			return n;
		}
		return fib(n - 1) + fib(n - 2);
	}

	void strrev(char* pl)
	{
		// scan to start point
		char* pr = pl;
		for (; *pr != 0; pr++);
		pr--;

		for (; pl < pr; pl++, pr--)
		{
			const char temp = *pl;
			*pl = *pr;
			*pr = temp;
		}
	}
	void StringCpy(const char* pSrc, char* pDst, int maxBufSize)
	{
		int n = 0;
		for (; *pSrc != 0 && n + 1 < maxBufSize; pSrc++, pDst++, n++)
		{
			*pDst = *pSrc;
		}
		*pDst = 0;
	}

	void int2str(int val, char* buf, int size)
	{
		char* const pStart = buf;
		char* const pEnd = buf + size;
		for (; val > 0 && (buf + 1 < pEnd); val /= 10, buf++)
		{
			*buf = '0' + val % 10;
		}
		*buf = 0;
		strrev(pStart);
	}
	class Database
	{
	private:
		class Entry
		{
		public:
			Entry() = default;
			Entry(const char* name, int value)
				:
				value(value) // cant go name(name) 
			{
				StringCpy(name, this->name, sizeof(this->name));
			}
			void Print() const
			{
				printWidth(name, nameBufferSize - 1);
				_putch('|');
				for (int n = 0; n < value; n++)
				{
					_putch('=');
				}
				_putch('\n');
			}
			void Serialize(std::ofstream& out) const
			{
				out.write(name, sizeof(name));
				out.write(reinterpret_cast<const char*>(&value), sizeof(value));
			}
			void Deserialize(std::ifstream& in)
			{
				in.read(name, sizeof(name));
				in.read(reinterpret_cast <char*>(&value), sizeof(value));
			}
		private:
			static constexpr int nameBufferSize = 20;
			char name[nameBufferSize];
			int value;
		};
	public:
		void Load(const char* filename)
		{
			std::ifstream in(filename, std::ios::binary);
			in.read(reinterpret_cast <char*>(&curNumEntries), sizeof(curNumEntries));
			for (int i = 0; i < curNumEntries; i++)
			{
				entries[i].Deserialize(in);
			}
		}
		void Save(const char* filename)
		{
			std::ofstream out(filename, std::ios::binary);
			out.write(reinterpret_cast<const char*>(&curNumEntries), sizeof(curNumEntries));
			for (int i = 0; i < curNumEntries; i++)
			{
				entries[i].Serialize(out);
			}
		}
		void Print() const
		{
			for (int i = 0; i < curNumEntries; i++)
			{
				entries[i].Print();
			}
		}
		void Add(const char* name, int value)
		{
			if (curNumEntries < maxNumEntries)
			{
				entries[curNumEntries++] = { name, value };
			}
		}
	private:
		static int constexpr maxNumEntries = 16;
		Entry entries[maxNumEntries];
		int curNumEntries = 0;
	};
}
int main()
{
	std::ifstream warpeace_file("war-peace.txt");
	constexpr int file_size = 3354046 + 1; //extra byte for null terminator, although we don't need it because every dobule windows
	char* warpeace_string= new char[file_size];	// newline will be converted into out 1 newline character so we will get extra space
	//above we allocate memory on heap for our data

	//we can allocate file size basing on the file size
	warpeace_file.seekg(0, std::ios_base::end);
	const int file_size2 = warpeace_file.tellg();
	warpeace_file.seekg(0, std::ios_base::beg);

	char* warpeace_string2 = new char[file_size2+1];

	//read into file
	int i = 0;
	for (char c = warpeace_file.get(); warpeace_file.good(); c = warpeace_file.get())
	{
		warpeace_string[i++] = c;
	}
	warpeace_string[i] = 0;

	// display actual number of butes copied into array
	char buffer[256];
	aguszka::int2str(i, buffer, sizeof(buffer));
	aguszka::print(buffer);

	delete[] warpeace_string; //way of deleting the string

	while (!_kbhit());

	return 0;
}