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
#include <functional>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
#define MAXN 100005
typedef long long ll;
typedef pair<int, int> pii;

/* Given an array A of N elements, print out the array after the Kth iteration of bubble sort.
N <= 100000
K <= N
Ai <= 10^9
*/











map<int, int> back;
int bit[MAXN];
void update(int i, int v) {
	i++;
	while (i < MAXN) {
		bit[i] += v;
		i += i & -i;
	}
}
int q(int i) {
	int sum = 0;
	i++;
	while (i > 0) {
		sum += bit[i];
		i -= i & -i;
	}
	return sum;
}
int query(int a, int b) {
	return q(b) - q(a - 1);
}
int a[MAXN];
int lft[MAXN];
int ans[MAXN];
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> v;
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	FOR(i, 0, n) {
		int nw = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		back[nw] = a[i];
		a[i] = nw;
	}
	priority_queue<pii, vector<pii>, greater<pii>> p;

	FOR(i, 0, n) {
		lft[i] = query(a[i] + 1, MAXN - 1);
		p.push({ lft[i], i });
		update(a[i], 1);
		a[i] = back[a[i]];
	}
	multiset<int> indexes;
	multiset<int> values;
	FOR(i, 0, k) {
		while (!p.empty() && p.top().first <= i) {
			indexes.insert(p.top().second);
			values.insert(a[p.top().second]);
			p.pop();
		}
		indexes.erase(indexes.begin());
		values.erase(--(values.end()));
	}
	auto itr1 = indexes.begin();
	auto itr2 = values.begin();
	while (itr1 != indexes.end()) {
		ans[*itr1 - k] = *itr2;
		++itr1;
		++itr2;
	}
	while (!p.empty()) {
		ans[p.top().second - k] = a[p.top().second];
		p.pop();
	}
	sort(a, a + n);
	FOR(i, 0, k) {
		ans[n - 1 - i] = a[n - 1 - i];
	}
	FOR(i, 0, n) {
		cout << ans[i] << endl;
	}
}