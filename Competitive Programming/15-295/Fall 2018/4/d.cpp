#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

int a, b, p, e;

vector<int> edges1[5005];
vector<int> edges2[5005];
int sz1[5001];
int sz2[5001];
bool visited[5001];
void dfs1(int u) {
	if (visited[u]) return;
	visited[u] = true;
	for (int v : edges1[u])
		dfs1(v);

}
void dfs2(int u) {
	if (visited[u]) return;
	visited[u] = true;
	for (int v : edges2[u])
		dfs2(v);

}

int main() {
	scanf("%d%d%d%d", &a, &b, &p, &e);
	FOR(i, 0, e) {
		int x, y;
		scanf("%d%d", &x, &y);
		edges1[x].push_back(y);
		edges2[y].push_back(x);
	}
	FOR(i, 0, p) {
		fill(visited, visited + p, false);
		dfs1(i);
		FOR(j, 0, p) if (visited[j]) sz1[i]++;
	}
	FOR(i, 0, p) {
		fill(visited, visited + p, false);
		dfs2(i);
		FOR(j, 0, p) if (visited[j]) sz2[i]++;
	}
	int ansa = p;
	int ansb = p;
	int ansc = 0;
	FOR(i, 0, p) {
		if (p - sz1[i] >= a) ansa--;
		if (p - sz1[i] >= b) ansb--;
		if (sz2[i] > b) ansc++;
	}
	cout << ansa << endl;
	cout << ansb << endl;
	cout << ansc << endl;
}

/*
3 4 7 8
0 4
1 2
1 5
5 2
6 4
0 1
2 3
4 5

*/

