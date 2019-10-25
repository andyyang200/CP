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
// given a weighted tree of N nodes (1 <= N <= 100000), find the sum of the distances between all pairs of nodes in the tree.
int p[100001];
vector<pii> edges[100001]; // {cost, neighboring node}
int sz[100001];
ll ans;
int n;
void dfs(int i)
{
	sz[i] = 1;
	for (pii j : edges[i])
	{
		if (j.second != p[i])
		{
			p[j.second] = i;
			dfs(j.second);
			sz[i] += sz[j.second];
			ans += j.first * sz[j.second] * (n - sz[j.second]);
		}
	}

}




int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
}