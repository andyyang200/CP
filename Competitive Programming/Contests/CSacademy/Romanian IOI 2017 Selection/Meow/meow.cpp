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
int p[100005];
int val[100005];
int newVal[100005];
vector<int> children[100005];
ll down[5005][5005];
ll up[100005];
ll sum, ans;
int qnum;
int sz;
void dfs(int i) {
	if (i >= sz) {
		return;
	}
	up[0] = 1;
	int newVal;
	scanf("%d", &newVal);
	ll x = up[newVal - 1];
	up[newVal] += x;
	up[newVal] %= M;
	sum -= up[val[i] - 1] * down[i][val[i] + 1] % M;
	sum = (sum + M) % M;
	sum += up[newVal - 1] * down[i][newVal + 1] % M;
	sum %= M;
	ans += sum * (qnum + i) % M;
	ans %= M;
	val[i] = newVal;
	for (int c : children[i]) {
		dfs(c);
	}
	up[newVal] -= x;
	up[newVal] = (up[newVal] + M) % M;
}
int main(void)
{
	int n, l, q;
	scanf("%d%d%d", &n, &l, &q);
	p[0] = -1;
	FOR(i, 1, n) {
		scanf("%d", &p[i]);
		children[p[i]].push_back(i);
	}
	FOR(i, 0, n) {
		scanf("%d", &val[i]);
		sort(children[i].begin(), children[i].end());
	}
	ans = 0;
	qnum = 1;
	while (q > 0) {
		sz = min(q, n);
		q -= sz;
		RFOR(i, n - 1, -1) {
			down[i][l + 1] = 1;
			FOR(j, 1, l + 1) {
				down[i][j] = 0;
				for (int c : children[i]) {
					down[i][j] += down[c][j];
					down[i][j] %= M;
				}
			}
			down[i][val[i]] += down[i][val[i] + 1];
			down[i][val[i]] %= M;
		}
		sum = down[0][1];
		dfs(0);
		qnum += sz;
	}
	cout << ans << endl;
}
