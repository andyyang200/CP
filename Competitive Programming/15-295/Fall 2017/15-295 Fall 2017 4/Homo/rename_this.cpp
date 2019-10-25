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
string s[100001];
int x[100001];

class SegmentTree
{
public:
	int* st;
	int length;
	SegmentTree(int n)
	{
		length = n;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
		build(0, 0, length - 1);
	}
	int f(int a, int b) // change for different problems
	{
		return max(a, b);
	}
	void build(int node, int l, int r)
	{
		if (l == r)
			st[node] = 0;
		else
		{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	void update(int i, int v)
	{
		update(0, 0, length - 1, i, v); //if sum query last parameter should be v - a[i], otherwise should be v
	}
	void update(int node, int sl, int sr, int i, int v)
	{
		if (i < sl || i > sr)
			return;
		if (sl == sr)
		{
			st[node] = v;
		}
		if (sl != sr)
		{
			int mid = (sl + sr) / 2;
			update(node * 2 + 1, sl, mid, i, v);
			update(node * 2 + 2, mid + 1, sr, i, v);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	int query(int ql, int qr)
	{
		return query(0, 0, length - 1, ql, qr);
	}
	int query(int node, int sl, int sr, int ql, int qr)
	{
		if (sl > qr || sr < ql)
			return -1;
		if (sl >= ql && sr <= qr)
			return st[node];
		int mid = (sl + sr) / 2;
		int a = query(node * 2 + 1, sl, mid, ql, qr);
		int b = query(node * 2 + 2, mid + 1, sr, ql, qr);
		if (a == -1)
			return b;
		if (b == -1)
			return a;
		return f(a, b);
	}
};
int main(void)
{
	freopen("homo.in", "r", stdin);
	freopen("homo.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> v;
	FOR(i, 0, n) {
		cin >> s[i] >> x[i];
		v.push_back(x[i]);
	}
	sort(v.begin(), v.end());
	FOR(i, 0, n) {
		x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
	}
	SegmentTree st(n + 5);
	multiset<int> ms;
	FOR(i, 0, n) {
		if (s[i] == "insert") {
			st.update(x[i], st.query(x[i], x[i]) + 1);
			ms.insert(x[i]);
		}
		if (s[i] == "delete") {
			int d = st.query(x[i], x[i]);
			if (d > 0) {
				st.update(x[i], d - 1);
			}
			auto itr = ms.find(x[i]);
			if (itr != ms.end()) {
				ms.erase(itr);
			}
		}
		bool homo = false;
		bool hetero = false;
		if (st.query(0, n) >= 2) {
			homo = true;
		}
		if (ms.size() >= 2 && *ms.begin() != *(--ms.end())) {
			hetero = true;
		}
		if (homo && hetero) {
			cout << "both" << endl;
		}
		else if (homo) {
			cout << "homo" << endl;
		}
		else if (hetero) {
			cout << "hetero" << endl;
		}
		else {
			cout << "neither" << endl;
		}
	}
}
/*
11
insert 1
insert 2
insert 1
insert 4
delete 1
delete 3
delete 2
delete 1
insert 4
delete 4
delete 4

*/