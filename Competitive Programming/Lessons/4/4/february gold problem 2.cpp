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
#define FOR(index, start, end) for(ll index = start; index < end; index++)
#define RFOR(index, start, end) for(ll index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;

int top[100000]; // fields on top of road
int bottom[100000]; // fields on bottom of road
int topLocation[100000]; // location of ith field in top
int bottomLocation[100000]; // location of ith field in bottom

int dp[1000][1000]; // dp[i][j] = maximum number of crosswalks using first i fields on top and first j fields on bottom
vector<int> connectionTop[1000]; // bottom location of possible connections for each top field
int main()
{
	FOR(i, 0, n)
	{
		FOR(j, top[i] - 4, top[i] + 5)
		{
			connectionTop[i].push_back(bottomLocation[j]);
		}
	}




	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			int k = connectBottom(i, j);
			dp[i][j] = max(dp[i][j], dp[i - 1][k - 1] + 1);
			k = connectTop(i, j);
			dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] + 1);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
		}
	}
	cout << dp[n - 1][n - 1] << endl;
}