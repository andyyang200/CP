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
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int L;
map<pii, bool> line;
bool behind[100];
pii offense[1001];
pii defense[1001];
int d[1001];
int b[1005];
int getd(pii a, pii b) {
	int dx = abs(a.first - b.first);
	int dy = abs(a.second - b.second);
	return dx * dx + dy * dy;
}
int main(void)
{
	cin >> L;
	FOR(i, 0, L) {
		int x, y;
		cin >> x >> y;
		line[{x, y}] = true;
	}
	FOR(i, 0, 5) {
		behind[i] = true;
		cin >> offense[i].first >> offense[i].second;
		FOR(j, 0, 55) {
			if (line[{offense[i].first, offense[i].second + j}]) {
				behind[i] = false;
				break;
			}
		}
	}
	FOR(i, 0, 5) {
		cin >> defense[i].first >> defense[i].second;
	}
	pii ball;
	cin >> ball.first >> ball.second;
	int maxd = 0;
	int minb = INF;
	FOR(i, 0, 5) {
		d[i] = INF;
		if (!behind[i])
			continue;
		FOR(j, 0, 5) {
			d[i] = min(d[i], getd(offense[i], defense[j]));
		}
		maxd = max(maxd, d[i]);
		b[i] = getd(offense[i], ball);
	}
	FOR(i, 0, 5) {
		if (!behind[i]) 
			continue;
		if (d[i] == maxd) {
			minb = min(minb, b[i]);
		}
	}
	vector<pii> ans;
	FOR(i, 0, 5) {
		if (!behind[i]) 
			continue;
		if (d[i] == maxd && b[i] == minb)
			ans.push_back(offense[i]);
	}
	sort(ans.begin(), ans.end());
	for (pii x : ans) {
		cout << x.first << " " << x.second << " ";
	}
	if (ans.size() == 0) {
		cout << -1 << " " << -1;
	}
	cout << endl;
}