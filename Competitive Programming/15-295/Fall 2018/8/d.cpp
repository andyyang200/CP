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


//---------------------------------------------------------------------------------------------------------------

int n, m;
vector<int> edges[501];
vector<int> cycle;
int p[501];
bool cycleFound;
int color[501];
void findCycle(int u) {
	if (cycleFound) return;
	color[u] = 1;
	for (int v : edges[u]) {
		if (cycleFound)  return;
		if (color[v] == 2) {
			continue;
		}
		if (color[v] == 1) {
			int i = u;
			while (i != v) {
				cycle.push_back(i);
				i = p[i];
			}
			cycle.push_back(v);




			cycleFound = true;
			return;
		}
		p[v] = u;
		findCycle(v);
	}
	color[u] = 2;
}
void checkdfs(int u, int badu, int badv) {
	color[u] = 1;
	for (int v : edges[u]) {
		if (u == badu && v == badv) continue;
		if (color[v] == 1) {
			cycleFound = true;
			return;
		}
		if (color[v] == 2) continue;
		checkdfs(v, badu, badv);
	}
	color[u] = 2;
}
bool check(int u, int v) {
	FOR(i, 0, n) {
		color[i] = 0;
	}
	cycleFound = false;
	FOR(i, 0, n) {
		if (color[i] == 0) checkdfs(i, u, v);
	}
	return cycleFound;
}

int main() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
	}

	FOR(i, 0, n) {
		if (!cycleFound && color[i] == 0) {
			findCycle(i);
		}
	}
	if (!cycleFound){
        cout << "YES" << endl;
        return 0;
	}

    cycle.push_back(cycle[0]);
	reverse(cycle.begin(), cycle.end());
	FOR(i, 0, cycle.size() - 1) {
		int u = cycle[i];
		int v = cycle[i + 1];
		bool hascycle = check(u, v);
		if (!hascycle) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

}
