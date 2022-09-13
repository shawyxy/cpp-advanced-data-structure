#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
namespace xy
{
	class Mystring
	{
	public:
		//µü´ْئ÷
		typedef char* iterator;
		typedef const char* const_iterator;

		// ´ٍس،؛¯ت‎
		void Print()
		{
			/*for (size_t i = 0; i < _size; i++)
			{
				cout << _str[i++] << " ";
			}

			cout << endl;*/
			cout << _str << endl;
		}
		void swap(Mystring& tmp)
		{
			std::swap(tmp._capacity, _capacity);
			std::swap(tmp._size, _size);
			std::swap(tmp._str, _str);
		}
		//¹¹شى؛¯ت‎
		//ؤعضأstringµؤsize²»°üہ¨\0,زٍ´ثزھ¶àز»¸ِ×ض½ع
		//´«ح³ذ´·¨
		Mystring(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new(char[_capacity + 1]);
			strcpy(_str, str);
		}
		//،°دض´ْذ´·¨،±
		//Mystring(const Mystring& s)
		//	//³ُت¼»¯ءذ±ي²»تا±طزھµؤ
		//	/*:_str(nullptr)
		//	,_size(0)
		//	,_capacity(0)*/
		//{
		//	Mystring tmp(s._str);
		//	swap(tmp._size, _size);
		//	swap(tmp._capacity, _capacity);
		//	swap(tmp._str, _str);
		//}
		//خِ¹¹؛¯ت‎
		~Mystring()
		{
			delete[] _str;
			_size = 0;
			_str = nullptr;
			_capacity = 0;
		}
		//µü´ْئ÷(begin،¢end)
		//؟ة¶ء؟ةذ´
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//ض»¶ء
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		//size
		size_t size()
		{
			return _size;
		}
		size_t capacity()
		{
			return _capacity;
		}
		//²ظ×÷·ûضطشط
		//·µ»طز‎سأتاخھءث¶ءذ´£¬¼سconstض»¶ء
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		//،°دض´ْ،±ذ´·¨
		Mystring& operator=(Mystring& s)
		{
			/*if (&s != this)
			{
				Mystring tmp(s._str);
				swap(tmp);
			}*/
			swap(s);

			return *this;
		}
		Mystring& operator+=(const char* s)
		{
			append(s);

			return *this;
		}
		Mystring& operator+=(char* s)
		{
			append(s);

			return *this;
		}
		Mystring& operator+(const char* s)
		{
			append(s);
			return *this;
		}
		Mystring& operator+(char* s)
		{
			append(s);
			return *this;
		}
		bool operator>=(const Mystring& s) const
		{
			return !(strcmp((*this)._str, s._str) < 0);
		}
		bool operator<=(const Mystring& s) const
		{
			return !(strcmp((*this)._str, s._str) > 0);
		}
		bool operator==(const Mystring& s) const
		{
			return strcmp((*this)._str, s._str) == 0;
		}
		bool operator>(const Mystring& s) const
		{
			return strcmp((*this)._str, s._str) > 0;
		}
		bool operator<(const Mystring& s) const
		{
			return strcmp((*this)._str, s._str) < 0;
		}
		//¹¦ؤـ؛¯ت‎:
		//¸ü¸ؤبفء؟
		void reserve(size_t n)
		{
			if (n > _capacity)//ہ©بف
			{
				char* tmp = new(char[n + 1]);
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
				//شھثط¸ِت‎خ´±ن
			}
			else//¼ُبف£¬دàµ±سعة¾³‎
			{
				_str[n] = '\0';
				_size = n;
			}
		}
		Mystring& insert(size_t pos, const char ch)
		{
			assert(pos <= _size);
			//ہ©بف
			if (_capacity == _size)
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			//زھإ²¶¯µؤت‎¾ف¸ِت‎£¬شظ¼سةد\0
			/*int num = _size - pos + 1;
			int tail = _size;
			while (num--)
			{
				_str[tail + 1] = _str[tail];
				tail--;
			}*/
			size_t tail = _size + 1;
			while (tail > pos)
			{
				_str[tail] = _str[tail - 1];
				tail--;
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}
		Mystring& insert(size_t pos, const char* s)
		{
			assert(pos <= _size);
			size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// إ²¶¯ت‎¾ف
			size_t end = _size + len;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, s, len);
			_size += len;

			return *this;
		}
		void push_back(char ch)
		{
			insert(_size, ch);
		}
		void append(const char* s)
		{
			insert(_size, s);
		}
		Mystring& substr(const Mystring& s);
		//صزµ½²¢·µ»طµعز»¸ِ×ض·ûµؤدآ±ê£¬·ٌشٍ·µ»ط-1
		size_t find(const char ch, size_t begin, size_t end) const
		{
			assert(begin <= end && (end <= _size));
			for (size_t i = begin; i <= end; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return -1;
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
			_capacity = 0;
		}
		void erase(size_t pos)
		{
			assert(pos >= 0);
			_str[pos] = '\0';
			_size = pos;
		}
	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	public:
		const static int npos = -1;
	};

	/*ostream& operator<<(ostream& os, Mystring& s);
	istream& operator>>(istream& is, Mystring& s);*/
	ostream& operator<<(ostream& os, Mystring& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			os << s[i];
		}
		return os;
	}
	istream& operator>>(istream& is, Mystring& s)
	{
		s.clear();
		const int N = 32;
		char ch = is.get();
		//×ش¶¨زه»؛³هاّ
		char buffer[N];
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			//´ïµ½»؛³هاّبفء؟£¬×î؛َ¼سةد\0
			if (i == N - 1)
			{
				buffer[i] = '\0';
				//ء¬½س
				s += buffer;
				i = 0;
			}
			//µü´ْ
			buffer[i++] = ch;
			ch = is.get();
		}
		//ء¬½س
		buffer[i] = '\0';
		s += buffer;

		return is;
	}

}