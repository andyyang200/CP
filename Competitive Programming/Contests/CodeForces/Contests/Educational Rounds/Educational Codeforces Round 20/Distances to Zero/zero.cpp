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
int a[200005];
int ans[200005];
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	FOR(i, 0, n) {
		ans[i] = INF;
	}
	int j = -INF;
	FOR(i, 0, n) {
		if (a[i] == 0) {
			j = i;
		}
		ans[i] = min(ans[i], i - j);
	}
	j = INF;
	RFOR(i, n - 1, -1) {
		if (a[i] == 0) {
			j = i;
		}
		ans[i] = min(ans[i], j - i);
	}
	FOR(i, 0, n) {
		cout << ans[i] << " ";
	}
	cout << endl;
}