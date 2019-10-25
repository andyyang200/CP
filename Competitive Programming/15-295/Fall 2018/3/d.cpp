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

vector<int> edges[3005];
map<string, bool> bad;
int d[3005][3005];
int pre[3005][3005];
bool visited[3005][3005];
int main() {

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	FOR(i, 0, k) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		z--;
		string s = to_string(x) + " " + to_string(y) + " " + to_string(z);
		bad[s] = true;
	}
	queue<pii> q;
	q.push({ 0, 0 });
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			d[i][j] = INF;
		}
	}
	d[0][0] = 0;
	visited[0][0] = true;
	pre[0][0] = 0;
	while (!q.empty()) {
		pii p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;
		if (y == n - 1) break;
		string s = to_string(x) + " " + to_string(y) + " ";
		for (int z : edges[y]) {
			if (visited[y][z] || bad[s + to_string(z)]) {
				continue;
			}
			visited[y][z] = true;
			d[y][z] = d[x][y] + 1;
			pre[y][z] = x;
			q.push({ y, z });
		}
	}
	int mind = INF;
	FOR(i, 0, n - 1) {
		mind = min(mind, d[i][n - 1]);
	}
	if (mind == INF){
        cout << -1 << endl;
        return 0;
	}
	vector<int> ans;
	FOR(i, 0, n - 1) {
		if (d[i][n - 1] == mind) {
			int y = i;
			int z = n - 1;
			ans.push_back(z);
			ans.push_back(y);
			while(y != 0){
                int x = pre[y][z];
                z = y;
                y = x;
                ans.push_back(y);
			}
			break;
		}
	}
	reverse(ans.begin(), ans.end());
	// assert(ans.size() - 1 == mind);
	cout << ans.size() - 1 << endl;
	for (int x : ans) {
		cout << x + 1 << " ";
	}
	cout << endl;
}

