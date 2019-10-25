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
map<pii, int> dp;
int n, k;
int f(int odd, int turn)
{
	if (odd < 0 || odd > n)
	{
		return -1;
	}
	if (n == k || odd == 0)
	{
		if (turn == 0)
		{
			if (odd % 2 == 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (odd % 2 == 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	auto itr = dp.find(make_pair(odd, turn));
	if (itr != dp.end())
	{
		return itr->second;
	}
	n--;
	int a = f(odd - 1, !turn);
	int b = f(odd, !turn);
	n++;
	int ans = 0;
	if (a == -1)
	{
		ans = b;
	}
	if (b == -1)
	{
		ans = a;
	}
	if (a && b)
	{
		ans = 0;
	}
	else
	{
		ans = 1;
	}
	dp[make_pair(odd, turn)] = ans;
	return ans;
}
int main()
{
	scanf("%d%d", &n, &k);
	int odd = 0;
	FOR(i, 0, n)
	{
		int a;
		scanf("%d", &a);
		if (a % 2 == 1)
		{
			odd++;
		}
	}
	int ans = f(odd, 1);
	if (ans)
	{
		cout << "Stannis" << "\n";
	}
	else
	{
		cout << "Daenerys" << "\n";
	}
}