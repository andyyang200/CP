//Andrew Yang
//Accepted
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
#define MAXN 100010
int a[MAXN];
int ans[MAXN];
int n;
bool bubble(int k)
{
	multiset<int> S;
	if (k == n) k--;
	for (int j = 0; j <= k; j++)
		S.insert(a[j]);
	for (int i = 0; i<n; i++)
	{
		ans[i] = *S.begin();
		S.erase(S.begin());
		if (i + k + 1 < n) S.insert(a[i + k + 1]);
	}
	FOR(i, 0, n - 1) {
		if (ans[i] > ans[i + 1]) {
			return false;
		}
	}
	return true;
}
int main(void)
{
	scanf("%d", &n);
	vector<int> v;
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	int l = 0;
	int r = n;
	int ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (bubble(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans + 1 << endl;
}