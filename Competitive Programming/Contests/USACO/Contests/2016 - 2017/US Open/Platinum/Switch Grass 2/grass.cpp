#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <unordered_map>
using namespace std;
#define FOR(i,a,n) for (int i=a;i<n;i++)
#define FORREV(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1000000007;
const int INF = 1e9;
const int p = 31
;map<int, pair<int, int>> todo; 
using namespace std;
map<int, set<int>> m[200001];
int N, M, K, Q, g[200002];
unordered_map<int, int> E[200001];

	map<PII, int> help; 

	void solve()
	{
		freopen("grass.in", "r", stdin);
		freopen("grass.out", "w", stdout);
		cin >> N;
		cin >> M;
		cin >> K;
		cin >> Q;
		for (int i = 0; i < M; i++)
		{
			int a; int b; int l;
			scanf("%d%d%d", &a, &b, &l);
			a--; b--;
			E[a][b] = -1;
			E[b][a] = -1;
			help[mp(a, b)] = l;
			help[mp(b, a)] = l;
		}
		FOR(i, 0, N) scanf("%d", &g[i]);
		multiset<int> s;
		for (int u = 0; u < N; u++) {


			for (auto itr = E[u].begin(); itr != E[u].end(); itr++)
			{
				int v = itr->first;
				itr->second = g[v];

				m[u][g[v]].insert( v );
				m[v][g[u]].insert( u );

				if (v > u && g[u] != g[v])
				{

					s.insert(help[mp(u, v)]);
				}

			}

		}
		FOR(q, 0, Q) {



			int a;
			int b;
			scanf("%d%d", &a, &b);
			a = a - 1;
			if (!(b != g[a])) continue;
			auto it = todo.begin();
			while (it != todo.end())
			{
				int updatingNode = it->fi;
				int ng = it->se.fi;
				auto itrUpdatingNode = E[a].find(updatingNode);
				if (itrUpdatingNode != E[a].end())
				{
					if (itrUpdatingNode->second != ng) {
						m[a][itrUpdatingNode->se].erase(m[a][itrUpdatingNode->se].find(updatingNode));
						m[a][ng].insert(updatingNode);
						itrUpdatingNode->se = ng;
						it->second.se--;
						if (it->second.se == 0) {

							it = todo.erase(it);

							continue;
						}
					}
				}
				it++;
			}
			for (auto it = m[a][g[a]].begin(); it != m[a][g[a]].end(); it++)	s.insert(help[mp(a, *it)]);
			g[a] = b;
			for (auto it = m[a][g[a]].begin(); it != m[a][g[a]].end(); it++)	s.erase(help[mp(a, *it)]);

			printf("%d\n", *s.begin());

			todo[a] = mp(b, E[a].size());
		}
	}
int main(void)
{
	solve();

}