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
set<int> edges[100005];
int color[100005];
int degree[100005];
int removed[100005];
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].insert(v);
		edges[v].insert(u);
		degree[u]++;
		degree[v]++;
	}
	queue<int> q;
	FOR(i, 0, n) {
		int cnt = 0;
		for (int j : edges[i]) {
			if (edges[j].size() == 1) {
				cnt++;
			}
		}
		if (cnt > 1) {
			cout << "First" << endl;
			return 0;
		}
		if (edges[i].size() == 1) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		if (removed[i]) {
			continue;
		}
		int p = -1;
		for (int j : edges[i]) {
			if (color[j] == 0) {
				p = j;
				break;
			}
		}
		if (p == -1) {
			continue;
		}
		removed[p] = true;
		removed[i] = true;
		color[p] = 1;
		color[i] = 2;
		for (int j : edges[p]) {
			if (removed[j]) {
				continue;
			}
			degree[j]--;
			if (degree[j] == 1){
				q.push(j);
			}
		}
	}
	FOR(i, 0, n) {
		bool win = true;
		if (color[i] == 2) {
			continue;
		}
		for (int j : edges[i]) {
			if (color[j] == 2) {
				win = false;
				break;
			}
		}
		if (win) {
			cout << "First" << endl;
			return 0;
		}
	}
	cout << "Second" << endl;
}
/*
5
1 2
1 3
2 4
3 5
*/