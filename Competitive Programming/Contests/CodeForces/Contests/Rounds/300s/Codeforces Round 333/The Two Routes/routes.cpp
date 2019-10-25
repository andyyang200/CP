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
bool edge[401][401];
bool visited[401];
int d[401];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		edge[a][b] = edge[b][a] = true;
	}
	if (edge[0][n - 1])
	{
		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				if (i != j)
				{
					edge[i][j] = !edge[i][j];
				}
			}
		}
	}
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		FOR(i, 0, n)
		{
			if (i != node && edge[node][i] && !visited[i])
			{
				visited[i] = true;
				d[i] = d[node] + 1;
				q.push(i);
			}
		}
	}
	if (visited[n - 1])
	{
		cout << d[n - 1] << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}