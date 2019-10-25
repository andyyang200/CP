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


bool intersect(int a, int b, int c, int d) {
	int t1 = a;
	int t2 = b;
	a = min(t1, t2);
	b = max(t1, t2);
	if (a < c && c < b && (d < a || d > b)) {
		return true;
	}
	swap(c, d);
	if (a < c && c < b && (d < a || d > b)) {
		return true;
	}



	return false;
}
int a[1005];
int b[1005];
vector<int> edges[1005];
int color[100005];
bool bad;
void dfs(int u) {
	for (int v : edges[u]) {
		if (color[v] == color[u]) {
			bad = true;
			break;
		}
		else if (color[v] == -1) {
			color[v] = color[u] ^ 1;
			dfs(v);
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {
		scanf("%d%d", &a[i], &b[i]);
	}
	FOR(i, 0, m) {
		FOR(j, i + 1, m) {
			if (intersect(a[i], b[i], a[j], b[j])) {
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}
	bad = false;
	fill(color, color + m, -1);
	FOR(i, 0, m) {
		if (color[i] == -1) {
			color[i] = 0;
			dfs(i);
		}
	}
	if (bad) {
		cout << "Impossible" << endl;
	}
	else {
		FOR(i, 0, m) {
			if (color[i] == 0) {
				printf("i");
			}
			else {
				printf("o");
			}
		}
		printf("\n");
	}

}


