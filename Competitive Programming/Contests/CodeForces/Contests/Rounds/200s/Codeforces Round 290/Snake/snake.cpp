#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;
char board[50][50];
int main()
{
	int n, m;
	cin >> n >> m;
	int r = 0;
	int c = 0;
	bool right = true;
	while (r < n)
	{
		board[r][c] = '#';
		if (c == 0 && !right)
		{
			r++;
			board[r][c] = '#';
			r++;
			right = true;
		}
		else if (c == m - 1 && right)
		{
			r++;
			board[r][c] = '#';
			r++;
			right = false;
		}
		else if (right)
		{
			c++;
		}
		else
		{
			c--;
		}
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (board[i][j] == '#')
			{
				cout << '#';
			}
			else
			{
				cout << '.';
			}
		}
		cout << endl;
	}
}