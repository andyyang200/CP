#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

char grid[5][5];
bool visited[5][5];
int maxLength, n;


void generate(int r, int c, int l, int open, bool closing)
{
	if (r < 0 || r >= n || c < 0 || c >= n) 
	{
		return;
	}
	if (visited[r][c])
	{
		return;
	}
	if (closing && grid[r][c] == '(')
	{
		return;
	}
	l++;

	if (!closing && grid[r][c] == ')')
	{
		closing = 1;
	}
	if (!closing)
	{
		open++;
	}
	if (l > maxLength && open * 2 == l)
	{
		maxLength = l;
	}

	visited[r][c] = 1;
	generate(r + 1, c, l, open, closing);
	generate(r - 1, c, l, open, closing);
	generate(r, c + 1, l, open, closing);
	generate(r, c - 1, l, open, closing);
	visited[r][c] = 0;
}

int main()
{
	ifstream fin("hshoe.in");
	ofstream fout("hshoe.out");

	fin >> n;
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			fin >> grid[r][c];
		}
	}

	generate(0, 0, 0, 0, 0);
	fout << maxLength << endl;
}