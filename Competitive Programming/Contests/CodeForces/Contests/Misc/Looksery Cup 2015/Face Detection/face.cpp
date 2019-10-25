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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
char grid[55][55];
int main()
{
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			cin >> grid[i][j];
		}
	}
	int ans = 0;
	FOR(i, 0, n - 1)
	{
		FOR(j, 0, m - 1)
		{
			string s = "    ";
			s[0] = grid[i][j];
			s[1] = grid[i + 1][j];
			s[2] = grid[i][j + 1];
			s[3] = grid[i + 1][j + 1];
			sort(s.begin(), s.end());
			if (s == "acef")
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
}