/*
ID: andyyan1
PROG: range
LANG: C++11
*/

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
char field[250][250];
int maxSquare[250][250];
map<int, int> squares;
int main()
{
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			cin >> field[i][j];
			if (field[i][j] == '0')
			{
				continue;
			}
			if (i - 1 < 0 || j - 1 < 0 || maxSquare[i - 1][j - 1] == 0)
			{
				maxSquare[i][j] = 1;
			}
			else
			{
				maxSquare[i][j] = maxSquare[i - 1][j - 1] + 1;
				int length = 1;
				for (int r = i - 1; r >= i - maxSquare[i][j] + 1; r--)
				{
					if (field[r][j] == '0')
					{
						break;
					}
					length++;
				}
				maxSquare[i][j] = min(length, maxSquare[i][j]);
				length = 1;
				for (int c = j - 1; c >= j - maxSquare[i][j] + 1; c--)
				{
					if (field[i][c] == '0')
					{
						break;
					}
					length++;
				}
				maxSquare[i][j] = min(length, maxSquare[i][j]);
			}
			FOR(l, 2, maxSquare[i][j] + 1)
			{
				squares[l]++;
			}
		}
	}
	for (auto itr = squares.begin(); itr != squares.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
}