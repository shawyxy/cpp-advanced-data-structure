#pragma once
struct BKDRHash
{
	size_t operator()(const string& s)
	{
		size_t value = 0;
		for (auto ch : s)
		{
			value = value * 131 + ch;
		}
		return value;
	}
};
struct APHash
{
	size_t operator()(const string& s)
	{
		size_t value = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if ((i & 1) == 0)
			{
				value ^= ((value << 7) ^ s[i] ^ (value >> 3));
			}
			else
			{
				value ^= (~((value << 11) ^ s[i] ^ (value >> 5)));
			}
		}
		return value;
	}
};
struct DJBHash
{
	size_t operator()(const string& s)
	{
		if (s.empty())
			return 0;
		size_t value = 5381;
		for (auto ch : s)
		{
			value += (value << 5) + ch;
		}
		return value;
	}
};
