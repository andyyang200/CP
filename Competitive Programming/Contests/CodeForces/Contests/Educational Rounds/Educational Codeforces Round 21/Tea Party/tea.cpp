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
pii a[101];
int filled[101];
int ans[101];
int main(void)
{
	int n, w;
	scanf("%d%d", &n, &w);
	FOR(i, 0, n) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	FOR(i, 0, n) {
		filled[i] = ceil((double)a[i].first / 2);
		w -= filled[i];
	}
	if (w < 0) {
		cout << -1 << endl;
		return 0;
	}
	RFOR(i, n - 1, -1) {
		int move = min(w, a[i].first - filled[i]);
		if (i < n - 1) {
			move = min(move, filled[i + 1]);
		}
		w -= move;
		filled[i] += move;
		if (w == 0) {
			break;
		}
	}
	if (w > 0) {
		cout << -1 << endl;
		return 0;
	}
	FOR(i, 0, n) {
		ans[a[i].second] = filled[i];
	}
	FOR(i, 0, n) {
		cout << ans[i] << " ";
	}
	cout << endl;
}