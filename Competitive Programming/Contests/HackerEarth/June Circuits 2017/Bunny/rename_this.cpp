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
int n;
int d;
string s;
bool visited[505];
int ans;
void dfs(int i, int x) {
	if (i == n - 1) {
		if (x == n) {
			ans++;
		}
		return;
	}
	if (s[i] == '?') {
		for (int j = max(0, i - d); j <= min(n - 1, i + d); j++)
		{
			if (!visited[j]) {
				visited[j] = true;
				dfs(j, x + 1);
				visited[j] = false;
			}
		}
	}
	else {
		int j = i - (s[i] - '0');
		if (j >= 0 && !visited[j]) {
			visited[j] = true;
			dfs(j, x + 1);
			visited[j] = false;
		}
		j = i + (s[i] - '0');
		if (j <= n - 1 && !visited[j]) {
			visited[j] = true;
			dfs(j, x + 1);
			visited[j] = false;
		}
	}
}
int main(void)
{
	cin >> s;
	n = s.length();
	scanf("%d", &d);
	ans = 0;
	visited[0] = true;
	dfs(0, 1);
	cout << ans << endl;
}