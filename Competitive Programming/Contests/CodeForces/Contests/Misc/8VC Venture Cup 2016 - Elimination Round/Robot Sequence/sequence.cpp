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

int main()
{
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	int ans = 0;
	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			int x = 0;
			int y = 0;
			FOR(k, i, j + 1)
			{
				if (s[k] == 'U')
				{
					y--;
				}
				if (s[k] == 'D')
				{
					y++;
				}
				if (s[k] == 'L')
				{
					x--;
				}
				if (s[k] == 'R')
				{
					x++;
				}
			}
			if (x == 0 && y == 0)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;

}