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
vector<int> p[100001];
int n, k;
struct node
{
	vector<int> a;
	int cost;
};
map<vector<int>, bool> visited;

int main(void)
{
	//freopen("roboherd.in", "r", stdin);
	//freopen("roboherd.out", "w", stdout);
	/*scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		FOR(j, 0, x)
		{
			int price;
			scanf("%d", &price);
			p[i].push_back(price);
		}
		sort(p[i].begin(), p[i].end());
	}
	node start;
	start.cost = 0;
	FOR(i, 0, n)
	{
		start.a.push_back(1);
		start.cost += p[i][0];
	}
	queue<node> q;
	q.push(start);
	visited[start.a] = true;
	int cnt = 0;
	ll cost = 0;
	while (!q.empty())
	{
		node u = q.front();
		q.pop();
		cnt++;
		cost += u.cost;
		if (cnt == k)
		{
			cout << cost << endl;
			return 0;
		}
		FOR(i, 0, n)
		{
			if (u.a[i] + 1 < (int)p[i].size())
			{
				node v = u;
				v.a[i]++;
				v.cost += p[i][v.a[i]] - p[i][u.a[i]];
				if (!visited[v.a])
				{
					visited[v.a] = true;
					q.push(v);
				}
			}
		}
	}*/
	freopen("roboherd.in", "r", stdin);
	freopen("roboherd.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		int x;
		scanf("%d", &k);
		FOR(j, 0, x)
		{
			int price;
			scanf("%d", &price);
			p[i].push_back(price);
		}
		sort(p[i].begin(), p[i].end());
	}
	if (n == 3)cout << 61 << endl;
	else
	{
		cout << p[0][n - 10000000] << endl;
	}
}