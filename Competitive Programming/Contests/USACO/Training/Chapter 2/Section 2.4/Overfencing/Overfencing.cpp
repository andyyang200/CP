/*
ID: andyyang200
PROG: maze1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

char map[205][85];
int steps[205][85];

bool possible(int r, int c)
{
	return (steps[r][c] == 0 && map[r][c] == ' ');
}

int main()
{
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");

	int rows = 0, cols = 0;
	fin >> cols >> rows;
	rows = 2 * rows + 1;
	cols = 2 * cols + 1;
	
	string line;
	getline(fin, line);

	int exit1Row = -1, exit1Col, exit2Row, exit2Col;

	for (int r = 0; r < rows; r++)
	{
		getline(fin, line);
		for (int c = 0; c < cols; c++)
		{
			map[r][c] = line[c];
			if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
			{
				if (map[r][c] == ' ')
				{
					if (exit1Row == -1)
					{
						exit1Row = r;
						exit1Col = c;
					}
					else
					{
						exit2Row = r;
						exit2Col = c;
					}
				}
			}
		}
	}

	int max = 0;
	steps[exit1Row][exit1Col] = 1;
	steps[exit2Row][exit2Col] = 1;
	queue<int> q;
	q.push(exit1Row);
	q.push(exit1Col);
	q.push(exit2Row);
	q.push(exit2Col);
	while (!q.empty())
	{
		int r = q.front();
		q.pop();
		int c = q.front();
		q.pop();

		if (steps[r][c] > max)
		{
			max = steps[r][c];
		}

		if (possible(r + 1, c))
		{
			q.push(r + 1);
			q.push(c);
			steps[r + 1][c] = steps[r][c] + 1;
		}
		if (possible(r - 1, c))
		{
			q.push(r - 1);
			q.push(c);
			steps[r - 1][c] = steps[r][c] + 1;
		}
		if (possible(r, c + 1))
		{
			q.push(r);
			q.push(c + 1);
			steps[r][c + 1] = steps[r][c] + 1;
		}
		if (possible(r, c - 1))
		{
			q.push(r);
			q.push(c - 1);
			steps[r][c - 1] = steps[r][c] + 1;
		}
	}

	fout << max / 2 << endl;
}

