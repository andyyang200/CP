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

bool d[1005][1005];
bool visited[1005];
int tos[1005];
int tot[1005];
int main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--;
	t--;
	FOR(i, 0, m) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		d[u][v] = 1;
		d[v][u] = 1;
	}
	queue<int> q;
	q.push(s);
	visited[s] = true;
	tos[s] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		FOR(i, 0, n) {
			if (d[x][i] && !visited[i]) {
				visited[i] = true;
				tos[i] = tos[x] + 1;
				q.push(i);
			}
		}
	}
	q.push(t);
	FOR(i, 0, n) visited[i] = false;
	visited[t] = true;
	tot[t] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		FOR(i, 0, n) {
			if (d[x][i] && !visited[i]) {
				visited[i] = true;
				tot[i] = tot[x] + 1;
				q.push(i);
			}
		}
	}
	int mind = tot[s];
	int ans = 0;
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			if (!d[i][j] && i != j) {
				if (tos[i] + 1 + tot[j] >= mind && tot[i] + 1 + tos[j] >= mind) ans++;
			}
		}
	}
	cout << ans / 2 << endl;
}
