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
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int startc, startr, endc, endr;
int v[10][10];
bool visited[10][10];
int sum;
int ans;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
int cnt;
int lim;
bool isvalid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && !visited[i][j];
}
void dfs(int i, int j) {
	if (cnt > lim) return;
	if (i == endc && j == endr) {
		ans = max(sum, ans);
		return;
	}
	FOR(x, 0, 4) {
		int ni = i + dx[x];
		int nj = j + dy[x];
		if (!isvalid(ni, nj)) continue;
		visited[ni][nj] = true;
		sum += v[ni][nj];
		cnt++;
		dfs(ni, nj);
		cnt--;
		visited[ni][nj] = false;
		sum -= v[ni][nj];
	}
}
int main(void)
{
	cin >> n >> m >> lim >> startc >> startr >> endc >> endr;
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			cin >> v[i][j];
		}
	}
	visited[startc][startr] = true;
	sum = 0;
	ans = 0;
	cnt = 0;
	sum += v[startc][startr];
	dfs(startc, startr);
	cout << ans << endl;
}