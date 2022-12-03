#pragma once

enum State
{
	EMPTY,
	EXIST,
	DELETE
};


//哈希表每个位置存储的结构
template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY; //状态
};
