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
int ans[105][105];
int a, b, n;
void print()
{
	FOR(i, 0, a)
	{
		FOR(j, 0, b)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	int pos = 1;
	if (b % 2 == 0)
	{
		FOR(i, 0, a)
		{
			if (i % 2 == 0)
			{
				FOR(j, 0, b)
				{
					ans[i][j] = pos++;
					if (pos > n)
					{
						print();
						return 0;
					}
				}
			}
			else
			{
				RFOR(j, b - 1, -1)
				{
					ans[i][j] = pos++;
					if (pos > n)
					{
						print();
						return 0;
					}
				}
			}
		}
	}
	else
	{
		FOR(i, 0, a)
		{
			FOR(j, 0, b)
			{
				ans[i][j] = pos++;
				if (pos > n)
				{
					print();
					return 0;
				}
			}
		}
	}
	cout << -1 << endl;
}