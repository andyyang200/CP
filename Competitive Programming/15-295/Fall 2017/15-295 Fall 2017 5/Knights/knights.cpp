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
int go[200005];
int come[200005];
queue<int> q[200005];
bool ans[200005];

void dfs1(int x);

void dfs2(int x) {
	if (!ans[x]) return;
	ans[x] = false;
	come[go[x]]--;
	if (come[go[x]] == 0){
		dfs1(go[x]);
	}
}

void dfs1(int x) {
	if (ans[x]) {
		return;
	}
	ans[x] = true;

	while (!q[x].empty()) {
		dfs2(q[x].front());
		q[x].pop();
	}
	q[go[x]].push(x);
	come[go[x]]++;
	dfs2(go[x]);
}

int main() {
	int n;
	cin >> n;
	FOR(i, 1, 2 * n + 1) {
		cin >> go[i];
	}
	FOR(i, 1, 2 * n + 1){
		if (come[i] == 0) {
			dfs1(i);
		}
	}
	FOR(i, 1, 2 * n + 1){
		if (ans[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
}
/*
4
5 6 7 7
1 3 2 3
*/