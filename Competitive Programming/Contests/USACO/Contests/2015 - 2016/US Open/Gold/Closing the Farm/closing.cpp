#include <iostream>
#include <vector>
using namespace std;
int p[200001];
int d[200001];
int cnt[200001];
vector<int> adj[200001];
int ans[200001];
int order[200001];
bool open[200001];
int findSet(int i){
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j){
	if (!isSameSet(i, j)){
		int x = findSet(i);
		int y = findSet(j);
		if (d[x] > d[y]){
			p[y] = x;
			cnt[x] += cnt[y];
		}
		else{
			p[x] = y;
			cnt[y] += cnt[x];
			if (d[x] == d[y])
				d[y]++;
		}
	}
}
int main()
{
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++){
		cin >> order[i];
		order[i]--;
		cnt[i] = 1;
		p[i] = i;
	}
	int openCnt = 0;
	for (int i = n - 1; i >= 0; i--){
		open[order[i]] = true;
		openCnt++;
		for (int j : adj[order[i]]){
			if (open[j]){
				unionSet(order[i], j);
			}
		}
		ans[i] = cnt[findSet(order[n - 1])] == openCnt;
	}
	for (int i = 0; i < n; i++){
		cout << (ans[i] ? "YES" : "NO") << endl;
	}
}