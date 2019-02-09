#include "matrix.hpp"
#include <iostream>

template<int M, int N>
void gaussian_elimination(Matrix<M, N>& m);

template<int M, int N >
std::array<double, N - 1> back_substitution(Matrix<M, N> m);

int main()
{
	Matrix<3, 4> ae;
	ae.m[0][0] = 6;
	ae.m[0][1] = 2;
	ae.m[0][2] = -1;
	ae.m[0][3] = 48;
	ae.m[1][0] = -3;
	ae.m[1][1] = 5;
	ae.m[1][2] = 3;
	ae.m[1][3] = 49;
	ae.m[2][0] = -2;
	ae.m[2][1] = 1;
	ae.m[2][2] = 3;
	ae.m[2][3] = 24;
	gaussian_elimination<3, 4>(ae);
	std::array<double, 3> sol = back_substitution<3, 4>(ae);
	for (int i = 0; i < sol.size(); i++)
	{
		std::cout << "x" << i << " = " << sol[i] << std::endl;
	}
	std::cin.get();
	return 0;
}

template<int M, int N>
void gaussian_elimination(Matrix<M, N>& m)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < M; j++)
		{
			double mult = -(m.m[j][i] / m.m[i][i]);
			for (int k = 0; k < N; k++)
			{
				double nw = m.m[j][k] + m.m[i][k] * mult;
				m.m[j][k] = nw;
			}
		}
	}
}

template<int M, int N>
std::array<double, N - 1> back_substitution(Matrix<M, N> m)
{
	std::array<double, N - 1> res;
	for (int i = M - 1; i > -1; i--)
	{
		double r = m.m[i][3];
		for (int j = i + 1; j < N - 1; j++)
		{
			r -= m.m[i][j] * res[j];
		}
		res[i] = r / m.m[i][i];
	}
	return res;
}