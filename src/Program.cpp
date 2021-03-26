#include <iomanip>
#include <iostream>

#define R 5
#define C 5
#define D 5

void dump_cube(int r, int c, int d, int cube[R][C][D])
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			for (int k = 0; k < d; k++)
				std::cout << std::setw(3) << std::setfill('0') << cube[i][j][k] << ' ';
			std::cout << '\t';
		}
		std::cout << '\n';
	}
}

int main()
{
	// Initialize the cube and fill it programmatically.
	int cube[R][C][D];
	int c = 1;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			for (int k = 0; k < D; k++)
				cube[i][j][k] = c++;

	dump_cube(R, C, D, cube);

	return 0;
}
