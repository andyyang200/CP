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
bool p[100005];
int exist[100005];
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		exist[x]++;
	}
	FOR(i, 2, 100001)
	{
		p[i] = true;
	}
	FOR(i, 2, 100001)
	{
		if (p[i])
		{
			for (int j = i + i; j <= 100000; j += i)
			{
				p[j] = false;
			}
		}
	}
	int ans = 1;
	FOR(i, 2, 100001)
	{
		if (p[i])
		{
			int x = 0;
			for (int j = i; j <= 100000; j += i)
			{
				x += exist[j];
			}
			ans = max(ans, x);
		}
	}
	cout << ans << endl;
}