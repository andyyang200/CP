#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define MAXN 1100

//---------------------------------------------------------------------------------------------------------------
int p[MAXN];
int res[MAXN][MAXN]; // initialize
int d[MAXN][MAXN];
ll mf, f;
int s, t; // initialize
int n; // initialize
int m;
void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	}
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}
int maxflow() {
	mf = 0;
	while (true) {
		f = 0;
		int dist[MAXN];
		FOR(i, 0, n) {
			dist[i] = 1000000000;
		}
		dist[s] = 0;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t) {
				break;
			}
			for (int v = 0; v < n; v++) {
				if (res[u][v] > 0 && dist[v] == 1000000000) {
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, 1000000000);
		if (f == 0) {
			break;
		}
		mf += f;
	}
	return mf;
}
int A[MAXN];
int B[MAXN];
vector<int> edges[MAXN];
int main() {
	cin >> n >> m;
	s = n * 2;
	t = n * 2 + 1;
	int sum = 0;
	int sum1 = 0;
	FOR(i, 0, n) {
		scanf("%d", &A[i]);
		sum1 += A[i];
	}
	FOR(i, 0, n) {
		scanf("%d", &B[i]);
		sum += B[i];
	}
	if (sum1 != sum) {
        cout << "NO" << endl;
        return 0;
	}
	FOR(i, 0, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	FOR(u, 0, n) {
		for (int v : edges[u]) {
			res[u][v + n] += 200 * 200;
			d[u][v + n] += 200 * 200;
		}
		res[u][u + n] += 200 * 200;
		d[u][u + n] += 200 * 200;
		res[s][u] += A[u];
		d[s][u] += A[u];
		res[u + n][t] += B[u];
		d[u + n][t] += B[u];
	}
	n  = 2 * n + 2;
    maxflow();
    n = (n - 2) / 2;
    db(mf);
	if (mf == sum) {
		cout << "YES" << endl;
		FOR(u, 0, n) {
			FOR(v, 0, n) {
				if (u == v) {
					int left = A[u];
					for (int k : edges[u]) {
						int go = d[u][k + n] - res[u][k + n];
						go = max(go, 0);
						left -= go;
					}
					cout << left << " ";
				}
				else {
					int go = d[u][v + n] - res[u][v + n];
                    go = max(go, 0);
					cout << go << " ";
				}
			}
			cout << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}

}
