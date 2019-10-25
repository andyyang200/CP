//Andrew Yang
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
#include <unordered_set>
#include <map>
#include <unordered_map>
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
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
char grid[4][4];
map<char, int> m;
int main(void)
{
	FOR(i, 0, 4)
	{
		FOR(j, 0, 4)
		{
			cin >> grid[i][j];
		}
	}
	FOR(i, 0, 4)
	{
		FOR(j, 0, 4)
		{
			if (i < 2)
			{
				m.clear();
				m[grid[i][j]]++;
				m[grid[i + 1][j]]++;
				m[grid[i + 2][j]]++;
				if (m['x'] == 2 && m['.'] == 1)
				{
					cout << "YES" << endl;
					return 0;
				}
			}
			if (j < 2)
			{
				m.clear();
				m[grid[i][j]]++;
				m[grid[i][j + 1]]++;
				m[grid[i][j + 2]]++;
				if (m['x'] == 2 && m['.'] == 1)
				{
					cout << "YES" << endl;
					return 0;
				}
			}
			if (i < 2 && j < 2)
			{
				m.clear();
				m[grid[i][j]]++;
				m[grid[i + 1][j + 1]]++;
				m[grid[i + 2][j + 2]]++;
				if (m['x'] == 2 && m['.'] == 1)
				{
					cout << "YES" << endl;
					return 0;
				}
			}
			if (i < 2 && j > 1)
			{
				m.clear();
				m[grid[i][j]]++;
				m[grid[i + 1][j - 1]]++;
				m[grid[i + 2][j - 2]]++;
				if (m['x'] == 2 && m['.'] == 1)
				{
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
}