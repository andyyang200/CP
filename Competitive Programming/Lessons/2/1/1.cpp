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

int f(int x)
{
	if (x <= 1)
	{
		return 1;
	}
	return f(x - 1) + f(x - 2);	
}

int dp[1000001];
int f2(int x)
{
	if (x <= 1)
	{
		return 1;
	}
	if (dp[x] == -1)
	{
		dp[x] = f2(x - 1) + f2(x - 2);
	}
	return dp[x];
}


int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);

	int n;
	cin >> n;

	cout << f(n) << endl;


	for (int i = 0; i <= n; i++)
	{
		dp[i] = -1;
	}
	cout << f2(n) << endl;




	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << endl;
}