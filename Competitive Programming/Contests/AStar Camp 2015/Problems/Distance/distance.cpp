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
#include <map>
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
#define MAXN 100001
typedef long long ll;
typedef pair<int, int> pii;
vector<int> edges[100001];
vector<int> e;
int P[MAXN][20];
int T[MAXN]; // parent
int L[MAXN]; // level
bool visited[MAXN];
void process(int N, int T[MAXN], int P[MAXN][20])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; 1 << j < N; j++)
			P[i][j] = -1;
	for (i = 0; i < N; i++)
		P[i][0] = T[i];
	for (j = 1; 1 << j < N; j++)
		for (i = 0; i < N; i++)
			if (P[i][j - 1] != -1)
				P[i][j] = P[P[i][j - 1]][j - 1];
}
int query(int N, int P[MAXN][20], int T[MAXN], int L[MAXN], int p, int q)
{
	int tmp, log, i;
	if (L[p] < L[q])
		tmp = p, p = q, q = tmp;
	for (log = 1; 1 << log <= L[p]; log++);
	log--;
	for (i = log; i >= 0; i--)
		if (L[p] - (1 << i) >= L[q])
			p = P[p][i];
	if (p == q)
		return p;
	for (i = log; i >= 0; i--)
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];

	return T[p];
}
int main()
{
	freopen("distance.in", "r", stdin);
	freopen("distance.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	FOR(i, 0, n - 1)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	stack<int> st;
	st.push(0);
	visited[0] = true;
	T[0] = -1;
	L[0] = 0;
	while (!st.empty())
	{
		int node = st.top();
		st.pop();
		FOR(i, 0, edges[node].size())
		{
			if (!visited[edges[node][i]])
			{
				visited[edges[node][i]] = true;
				L[edges[node][i]] = L[node] + 1;
				T[edges[node][i]] = node;
				st.push(edges[node][i]);
			}
		}
	}
	process(n, T, P);
	FOR(i, 0, q)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		int lca = query(n, P, T, L, a, b);
		cout << L[a] + L[b] - 2 * L[lca] << endl;
	}
}