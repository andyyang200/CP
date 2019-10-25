#include <iostream>
#include <vector>
using namespace std;

vector<int> adjList[3001];
bool visited[3001];
bool closed[3001];
void dfs(int cur){
	if (visited[cur] || closed[cur]){
		return;
	}
	visited[cur] = true;
	for (int x : adjList[cur]){
		dfs(x);
	}
}
int main()
{
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int x = 0; x < m; x++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	dfs(0);
	bool connected = true;
	for (int x = 0; x < n; x++)
		if (!visited[x] && !closed[x])
			connected = false;
	cout << (connected ? "YES" : "NO") << endl;
	for (int x = 0; x < n - 1; x++){
		int u;
		cin >> u;
		u--;
		closed[u] = true;
		for (int y = 0; y < n; y++)visited[y] = false;
		for (int y = 0; y < n; y++)
			if (!visited[y] && !closed[y]){
				dfs(y);
				break;
			}
				
		connected = true;
		for (int y = 0; y < n; y++)
			if (!visited[y] && !closed[y])
				connected = false;
		cout << (connected ? "YES" : "NO") << endl;
	}
}