#include <cctype>
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
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> edges[200001];
int type[200001];	
int main(void)
{
	freopen("grass.in","r",stdin);
	freopen("grass.out","w",stdout);
	int N, M, K, Q;
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	FOR(i, 0, M)
	{
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		u--, v--;
		edges[u].push_back({ l, v });
		edges[v].push_back({ l, u });
	}
	FOR(i, 0, N)
	{
		scanf("%d", &type[i]);
	}
	multiset<int> s;
	FOR(i, 0, N)
	{
		for (pii j : edges[i])
		{
			if (j.second>i &&type[i] != type[j.second])
			{
				s.insert(j.first);
			}
		}
	}
	FOR(i, 0, Q)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		for (pii j : edges[a])
		{
			if (type[j.second] == type[a] && type[j.second] != b)
			{
				s.insert(j.first);
			}
			if (type[j.second] != type[a] && type[j.second] == b)
			{
				s.erase(s.find(j.first));
			}
		}
		type[a] = b;
		printf("%d\n", *s.begin());
	}
}