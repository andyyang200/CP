#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
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
#include <climits>

using namespace std;

char crossword[51][51];
bool isClue[51][51];
int n, m;

bool isVerticalClue(int r, int c)
{
	return crossword[r][c] != '#' && r + 2 < n && (r == 0 || crossword[r - 1][c] == '#') && crossword[r + 1][c] == '.' && crossword[r + 2][c] == '.';
}
bool isHorizontalClue(int r, int c)
{
	return crossword[r][c] != '#' && c + 2 < m && (c == 0 || crossword[r][c - 1] == '#') && crossword[r][c + 1] == '.' && crossword[r][c + 2] == '.';
}

int main()
{
	freopen("crosswords.in", "r", stdin);
	freopen("crosswords.out", "w", stdout);

	cin >> n >> m;

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			cin >> crossword[r][c];
		}
	}
	int count = 0;
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			if (isHorizontalClue(r, c) || isVerticalClue(r, c))
			{
				isClue[r][c] = true;
				count++;
			}
		}
	}
	cout << count << endl;
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			if (isClue[r][c])
			{
				cout << r + 1 << " " << c + 1 << endl;
			}
		}
	}
}