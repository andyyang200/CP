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
int a[100005];
int l[100005];
int r[100005];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, 100005) {
		l[i] = INF;
		r[i] = -1;
	}
	FOR(i, 0, n) {
		cin >> a[i];
		l[a[i]] = min(l[a[i]], i);
		r[a[i]] = max(r[a[i]], i);
	}
	int j = 0;
	int i = 0;
	int ans = 0;
	while (i < n) {
		while (i <= j) {
			j = max(j, r[a[i]]);
			i++;
		}
		j = i;
		ans++;
	}
	cout << ans << endl;
}