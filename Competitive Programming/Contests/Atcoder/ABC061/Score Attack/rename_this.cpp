//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>	
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1e18
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;	
vector<pii> edges[1001];
bool visited[1001];
ll maxD[1001];
ll ans;
int n, m;
int canreach[1005];
void dfs(int i, ll d) {
	if (visited[i]) {
		if (canreach[i] && d > maxD[i])
		{
			ans = -1;
		}
		return;
	}
	maxD[i] = d;
	visited[i] = true;
	for (pii c : edges[i]) {
		dfs(c.first, d + c.second);
	}
}
void dfs(int i) {
	if (visited[i]) {
		return;
	}
	visited[i] = true;
	for (pii c : edges[i]) {
		dfs(c.first);
	}
}

bool check(int i) {
	dfs(i);
	canreach[i] = visited[n - 1];
	FOR(i, 0, n) {
		visited[i] = false;
	}

}
int main(void)
{
	cin >> n >> m;
	FOR(i, 0, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		edges[a].push_back({ b, c });
	}
	FOR(i, 0, n) {
		check(i);
	}
	ans = 0;
	dfs(0, 0);
	if (ans == -1) {
		cout << "inf" << endl;
		return 0;
	}
	cout << maxD[n - 1] << endl;
	
}