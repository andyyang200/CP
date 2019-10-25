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

/*
There are N cows in the plane. Two cows are "soulmates" if the rectangle with those two cows as opposite corners
has positive area and contains no other cows, even on its border. How many cows have at least one soulmate?

N <= 100000
-10^9 <= Xi, Yi <= 10^9
*/










pii a[100005];
multiset<int> byX[100005];
multiset<int> byY[100005];
class SegmentTree
{
public:
	vector<int>* st;
	int length;
	SegmentTree(int n)
	{
		length = n;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new vector<int>[maxSize];
		build(0, 0, length - 1);
	}
	void build(int node, int l, int r)
	{
		FOR(x, l, r + 1) {
			for (int y : byX[x]) {
				st[node].push_back(y);
			}
		}
		sort(st[node].begin(), st[node].end());
		if (l == r) {
			return;
		}
		else {
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
		}

	}
	int query(int node, int sl, int sr, int x1, int x2, int y1, int y2)
	{
		if (sl > x2 || sr < x1)
			return 0;
		if (sl >= x1 && sr <= x2)
		{
			if (st[node].size() == 0) {
				return 0;
			}
			int low = INF;
			int l = 0;
			int r = st[node].size() - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (st[node][mid] < y1) {
					l = mid + 1;
				}
				else if (st[node][mid] > y2) {
					r = mid - 1;
				}
				else {
					low = mid;
					r = mid - 1;
				}
			}
			int high = -1;
			l = 0;
			r = st[node].size() - 1;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (st[node][mid] < y1) {
					l = mid + 1;
				}
				else if (st[node][mid] > y2) {
					r = mid - 1;
				}
				else {
					high = mid;
					l = mid + 1;
				}
			}
			if (low <= high) {
				return high - low + 1;
			}
			else
				return 0;

		}
		int mid = (sl + sr) / 2;
		int a = query(node * 2 + 1, sl, mid, x1, x2, y1, y2);
		int b = query(node * 2 + 2, mid + 1, sr, x1, x2, y1, y2);
		return a + b;
	}
	int query(int x1, int x2, int y1, int y2)
	{
		if (x1 > x2 || y1 > y2) return 0;
		return query(0, 0, length - 1, x1, x2, y1, y2);
	}

};
map<pii, int> bad;
map<pii, int> seen;
int main(void)
{
	int n;
	scanf("%d", &n);
	set<int> s;
	FOR(i, 0, n) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	FOR(i, 0, n) {
		s.insert(a[i].first);
		s.insert(a[i].second);
	}
	vector<int> v;
	for (int x : s) {
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	FOR(i, 0, n) {
		int x = lower_bound(v.begin(), v.end(), a[i].first) - v.begin() + 1;
		int y = lower_bound(v.begin(), v.end(), a[i].second) - v.begin() + 1;
		a[i].first = x;
		a[i].second = y;
		byX[x].insert(y);
		byY[y].insert(x);
	}
	SegmentTree st(n + 10);
	int ans = 0;
	FOR(i, 0, n) {
		if (bad[{a[i].first, a[i].second}]) {
			continue;
		}
		int x = a[i].first;
		int y = a[i].second;
		auto itr = byX[x].upper_bound(y);
		int up = -1;
		if (itr == byX[x].end()) {
			up = n + 3;
		}
		else {
			up = *itr;
		}
		itr = byX[x].lower_bound(y);
		int down = -1;
		if (itr == byX[x].begin()) {
			down = 0;
		}
		else {
			itr--;
			down = *itr;
		}
		auto itr2 = byY[y].upper_bound(x);
		int right = -1;
		if (itr2 == byY[y].end()) {
			right = n + 3;
		}
		else {
			right = *itr2;
		}
		itr2 = byY[y].lower_bound(x);
		int left = -1;
		if (itr2 == byY[y].begin()) {
			left = 0;
		}
		else {
			itr2--;
			left = *itr2;
		}
		bool good = false;
		if (st.query(left + 1, x - 1, y + 1, up - 1) > 0) {
			good = true;
		}
		else if (st.query(x + 1, right - 1, y + 1, up - 1) > 0) {
			good = true;
		}
		else if (st.query(left + 1, x - 1, down + 1, y - 1) > 0) {
			good = true;
		}
		else if (st.query(x + 1, right - 1, down + 1, y - 1) > 0) {
			good = true;
		}
		if (good) {
			ans++;
		}
	}
}













