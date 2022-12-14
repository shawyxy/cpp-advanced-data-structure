#pragma once
namespace xy
{
	template<size_t N>		// N个比特位	
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize(N / 8 + 1, 0);
		}
		void set(size_t pos)
		{
			assert(pos < N);

			size_t x = pos / 8;		// 在x个char
			size_t y = pos % 8;		// 在这个char的第y个比特位
			_bits[x] |= (1 << y);	// 将这个比特位设为1
		}
	private:
		vector<char> _bits; // 以char为单位管理
	};

	void test1()
	{
		bitset<8> bs;
		bs.set(2);
	}
}