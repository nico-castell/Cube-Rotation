#include <iomanip>
#include <iostream>

#define R 4
#define C 4
#define D 4

/// @brief Dump a 3-dimensional array to the console
/// @param r Index of last row
/// @param c Index of last column
/// @param d Index of depth
/// @param cube The cube to print
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

/// @brief Rotate the cube clockwise "from the top"
/// @param r The number of rows "from the front"
/// @param c The number of columns "from the front"
/// @param d The index of depth "from the front"
/// @param cube The 3-dimensional array to be used as the cube
void rotate_cube(const int& r, const int& c, const int& d, int cube[R][C][D])
{
	for (int row = 0; row < r; row++)
	{
		int col = 0, dep = 0;    // Declare starting points at 0
		int ecol = c, edep = d;  // Isolate endings in each layer of the cube from the constant size of the cube
		int prev, curr;

		/**
		 * col  - Starting column index
		 * ecol - Ending column index
		 * dep  - Starting depth index
		 * edep - Ending depth index
		 * i    - Iterator
		 */

		while (col < ecol && dep < edep)
		{
			if (col + 1 == ecol || dep + 1 == edep)
				break;

			// Store the first element of next depth, this element will replace the first element of current depth.
			prev = cube[row][col][dep + 1];

			// Rotate front side
			for (int i = col; i < ecol; i++)
			{
				curr = cube[row][i][dep];  // Store value of position for later
				cube[row][i][dep] = prev;  // Override current position
				prev = curr;               // Update value of next position
			}
			dep++;

			// Rotate right side
			for (int i = dep; i < edep; i++)
			{
				curr = cube[row][edep - 1][i];  // Store value of position for later
				cube[row][edep - 1][i] = prev;  // Override current position
				prev = curr;                    // Update value of next position
			}
			ecol--;

			// Rotate back side
			for (int i = ecol - 1; i >= col; i--)
			{
				curr = cube[row][i][edep - 1];  // Store value of position for later
				cube[row][i][edep - 1] = prev;  // Override current position
				prev = curr;                    // Update value of next position
			}
			edep--;

			// Rotate left side
			for (int i = edep - 1; i >= dep; i--)
			{
				curr = cube[row][col][i];  // Store value of position for later
				cube[row][col][i] = prev;  // Override current position
				prev = curr;               // Update value of next position
			}
			col++;
		}
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

	std::cout << "\033[36mOriginal:\033[00m\n";
	dump_cube(R, C, D, cube);

	rotate_cube(R, C, D, cube);
	std::cout << "\n\033[36mModified:\033[00m\n";
	dump_cube(R, C, D, cube);

	return 0;
}
