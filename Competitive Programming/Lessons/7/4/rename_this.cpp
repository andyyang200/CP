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

/* you are given a tree. Each node contains a value. 
You choose a set of nodes and sum their values. 
What is the total value possible, if no two nodes in the set
can be adjacent?
*/
int n;
vector<int> edges[100001];
int p[100001];
int val[100001];
int dp[100001][2];
void dfs(int node)
{
	for (int c : edges[node])
	{
		if (c == p[node])
		{
			continue;
		}
		p[c] = node;
		dfs(c);
	}
	dp[node][0] = 0;
	for (int c : edges[node])
	{
		if (c == p[node])
		{
			continue;
		}
		dp[node][0] += max(dp[c][0], dp[c][1]);
	}
	dp[node][1] = val[node];
	for (int c : edges[node])
	{
		if (c == p[node])
		{
			continue;
		}
		dp[node][1] += dp[c][0];
	}

}










int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
}