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
map<string, int> m;
set<int> b;
set<int> e;
int ans[100];
int n;
void f(int floor, int t) {
	if (t >= ans[floor]) {
		return;
	}
	ans[floor] = t;
	if (e.find(floor) != e.end()) {
		for (int x : e) {
			f(x, t + abs(x - floor) * 5 + 15);
		}
	}
	if (floor > 0) {
		f(floor - 1, t + 10);
	}
	if (floor < n - 1) {
		f(floor + 1, t + 20);
	}
}
int main(void)
{
	cin >> n;
	int B;
	cin >> B;
	FOR(i, 0, B) {
		int x;
		cin >> x;
		b.insert(x);
	}
	int E;
	cin >> E;
	FOR(i, 0, E) {
		int x;
		cin >> x;
		e.insert(x);
	}
	int start;
	cin >> start;
	FOR(i, 0, n) {
		ans[i] = INF;
	}
	f(start, 0);
	int ret = INF;
	for (int x : b) {
		ret = min(ret, ans[x]);
	}

	cout << ret << endl;
}