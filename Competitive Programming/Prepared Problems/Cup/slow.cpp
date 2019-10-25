#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int a[2000005];
int par[2000005];
int sz[2000005];
int m, n;

int getPar(int v) {
	return par[v] == -1 ? v : par[v] = getPar(par[v]);
}
bool unite(int v, int u) {
	v = getPar(v);
	u = getPar(u);
	if (v == u) return false;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	return true;
}

int getdist(int a, int b) {
	int ans = 0;
	FOR(i, 0, m) {
		bool x = (1 << i) & a;
		bool y = (1 << i) & b;
		if (x == y) {
			ans++;
		}
	}
	return ans;
}
int main(void)
{
	scanf("%d%d", &m, &n);
	vector<pair<int, pii>> e;
	string id;
	FOR(i, 0, n) {
		cin >> id;
		for (int j = 0; j < m; ++j)
			if (id[j] == '1')
				a[i] |= (1 << j);
		par[a[i]] = -1;
	}
	FOR(i, 0, n) {
		FOR(j, i + 1, n) {
			e.push_back({ getdist(a[i], a[j]),{ a[i], a[j] } });
		}
	}
	sort(e.begin(), e.end());
	reverse(e.begin(), e.end());
	int cnt = 0;
	int ans = 0;
	for (auto p : e) {
		int u = p.second.first;
		int v = p.second.second;
		if (unite(u, v)) {
			cnt++;
			ans += p.first;
		}
		if (cnt == n - 1) {
			break;
		}
	}
	cout << ans << endl;
}

/*
5 5
10010
00101
11111
01010
10101
*/

