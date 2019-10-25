//Andy Yang
#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;



int visited[100005][2];
int pre[100005][2];
vector<int> edges[100005];
bool t;
void dfs(int node, int turn) {
	if (visited[node][1] == 1 || visited[node][0] == 1) {
		t = true;
	}
	if (visited[node][turn]) {
		return;
	}
	visited[node][turn] = 1;
	int turn2 = (turn + 1) % 2;
	for (int edge : edges[node]) {
		if (!visited[edge][turn2])
			pre[edge][turn2] = node;
		dfs(edge, turn2);
	}
	visited[node][turn] = 2;
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n) {
		int c;
		scanf("%d", &c);
		FOR(j, 0, c) {
			int e;
			scanf("%d", &e);
			e--;
			edges[i].push_back(e);
		}
	}
	int s;
	cin >> s;
	s--;
	t = false;
	dfs(s, 0);
	FOR(i, 0, n) {
		if (edges[i].size() == 0 && visited[i][1]) {
			int turn = 1;
			vector<int> ans;
			while (i != s || turn > 0) {
				ans.push_back(i);
				i = pre[i][turn];
				turn = (turn + 1) % 2;
			}
			ans.push_back(s);
			assert(ans.size() % 2 == 0);
			reverse(ans.begin(), ans.end());
			cout << "Win" << endl;
			for (int x : ans) {
				cout << x + 1 << " ";
			}
			cout << endl;
			return 0;
		}
	}
	if (t) cout << "Draw" << endl;
	else cout << "Lose" << endl;
}
