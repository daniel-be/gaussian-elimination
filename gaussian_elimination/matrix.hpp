#pragma once
#include <array>

template<int M, int N>
struct Matrix
{
	std::array<std::array<double, N>, M> m;
};