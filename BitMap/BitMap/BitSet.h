#pragma once
namespace xy
{
	template<size_t N>		// N������λ	
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

			size_t x = pos / 8;		// ��x��char
			size_t y = pos % 8;		// �����char�ĵ�y������λ
			_bits[x] |= (1 << y);	// ���������λ��Ϊ1
		}
	private:
		vector<char> _bits; // ��charΪ��λ����
	};

	void test1()
	{
		bitset<8> bs;
		bs.set(2);
	}
}