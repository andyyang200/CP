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
char grid[1005][1005];
bool visited[1005][1005][5][3];
bool ans;
void dfs(int r, int c, int dir, int turns) {
	if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '*' || turns < 0) {
		return;
	}
	if (visited[r][c][dir][turns]) {
		return;
	}
	visited[r][c][dir][turns] = true;
	if (grid[r][c] == 'T')
	{
		ans = true;
		return;
	}
	if (dir == 1) {
		dfs(r - 1, c, dir, turns);
		dfs(r, c - 1, 4, turns - 1);
		dfs(r, c + 1, 2, turns - 1);
	}
	if (dir == 2) {
		dfs(r, c + 1, dir, turns);
		dfs(r - 1, c, 1, turns - 1);
		dfs(r + 1, c, 3, turns - 1);
	}
	if (dir == 3) {
		dfs(r + 1, c, dir, turns);
		dfs(r, c - 1, 4, turns - 1);
		dfs(r, c + 1, 2, turns - 1);
	}
	if (dir == 4) {
		dfs(r, c - 1, dir, turns);
		dfs(r - 1, c, 1, turns - 1);
		dfs(r + 1, c, 3, turns - 1);
	}
}
int main(void)
{
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			cin >> grid[i][j];
		}
	}
	ans = false;
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			if (grid[i][j] == 'S') {
				dfs(i, j, 1, 2);
				dfs(i, j, 2, 2);
				dfs(i, j, 3, 2);
				dfs(i, j, 4, 2);
				break;
			}
		}
	}
	if (ans) {
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}