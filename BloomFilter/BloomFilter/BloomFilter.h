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

template<size_t N,
class K = string, class Hash1 = BKDRHash, class Hash2 = APHash, class Hash3 = DJBHash>
class BloomFilter
{
public:
	void Set(const K& key)
	{
		size_t hash1 = Hash1()(key) % N;
		size_t hash2 = Hash2()(key) % N;
		size_t hash3 = Hash3()(key) % N;

		_bs.set(hash1);
		_bs.set(hash2);
		_bs.set(hash3);
	}
	bool Test(const K& key)
	{
		size_t hash1 = Hash1()(key) % N;
		if (_bs.test(hash1) == false)
		{
			return false;				// 准确
		}

		size_t hash2 = Hash2()(key) % N;
		if (_bs.test(hash2) == false)
		{
			return false;				// 准确
		}

		size_t hash3 = Hash3()(key) % N;
		if (_bs.test(hash3) == false)
		{
			return false;				// 准确
		}

		return true;					// 可能误判
	}
private:
	bitset<N> _bs;
};