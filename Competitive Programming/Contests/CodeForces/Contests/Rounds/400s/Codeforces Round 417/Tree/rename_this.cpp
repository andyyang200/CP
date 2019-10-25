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

int N, a[100100], x, o[1 << 24], e[1 << 24], numo, nume;
vector<int> ch[100100];
ll ans;

int dfs(int i) {
	int p = 1;
	for (int j : ch[i]) p = 1 ^ dfs(j);
	if (p) x ^= a[i], o[a[i]]++, numo++;
	else e[a[i]]++, nume++;
	return p;
}

int main() {
	scanf("%d", &N);
	FOR(i, 0, N) scanf("%d", &a[i]);
	FOR(i, 1, N) {
		int p; scanf("%d", &p), p--;
		ch[p].push_back(i);
	}
	dfs(0);

	if (!x) {
		ans += 1ll * nume * (nume - 1) / 2;
		ans += 1ll * numo * (numo - 1) / 2;
	}
	FOR(i, 0, 1 << 24) {
		ans += 1ll * e[x^i] * o[i];
	}

	printf("%lld\n", ans);
	return 0;
}