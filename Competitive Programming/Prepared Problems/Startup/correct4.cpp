#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1010;
vector<int> G[N];
vector<int> g[N];
int n, m, k;
int id[N][2];
int revId[2][N];
bool used[N];
int mt[N];

bool dfs(int x) {
	if (used[x]) return false;
	used[x] = 1;
	for (int y : g[x]) {
		if (mt[y] == -1 || dfs(mt[y])) {
			mt[y] = x;
			return true;
		}
	}
	return false;
}

int kuhn() {
	for (int i = 0; i < k; i++)
		mt[i] = -1;
	for (int i = 0; i < m; i++)
		used[i] = 0;
	int res = 0;
	for (int i = 0; i < m; i++) {
		if (dfs(i)) {
			res++;
			for (int j = 0; j < m; j++)
				used[j] = 0;
		}
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	for (int v = 0; v < n; v++) {
		if ((int)G[v].size() < (n - 1) / 2) continue;
		for (int i = 0; i < n; i++)
			id[i][1] = -1;
		id[v][1] = -2;
		m = k = 0;
		for (int u : G[v]) {
			revId[0][m] = u;
			id[u][0] = m++;
			id[u][1] = 0;
		}
		for (int u = 0; u < n; u++) {
			if (id[u][1] != -1) continue;
			revId[1][k] = u;
			id[u][0] = k++;
			id[u][1] = 1;
		}
		for (int i = 0; i < m; i++) {
			g[i].clear();
			for (int u : G[revId[0][i]])
				if (id[u][1] == 1)
					g[i].push_back(id[u][0]);
		}
		if (kuhn() < k) continue;
		printf("Yes\n");
		printf("%d %d\n", v + 1, n - 1 - k);
		for (int i = 0; i < n; i++)
			used[i] = 0;
		used[v] = 1;
		for (int i = 0; i < k; i++) {
			int u = revId[1][i], w = revId[0][mt[i]];
			used[u] = used[w] = 1;
			printf("%d %d\n", u + 1, w + 1);
		}
		for (int i = 0; i < n; i++)
			if (!used[i])
				printf("%d -1\n", i + 1);
		return 0;
	}
	printf("No\n");

	return 0;
}
