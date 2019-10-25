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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> switches[100][100];
bool visited[100][100];
bool lights[100][100];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int n;
void dfs(int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= n || !lights[r][c] || visited[r][c])
	{
		return;
	}
	visited[r][c] = true;
	FOR(i, 0, switches[r][c].size())
	{
		lights[switches[r][c][i].first][switches[r][c][i].second] = 1;
	}
	FOR(i, 0, 4)
	{
		dfs(r + dx[i], c + dy[i]);
	}
}
int main()
{
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	int m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a--;
		b--;
		c--;
		d--;
		switches[a][b].push_back({ c, d });
	}
	lights[0][0] = 1;
	dfs(0, 0);
	int ans = 0;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			ans += lights[i][j];
		}
	}
	cout << ans << endl;

}