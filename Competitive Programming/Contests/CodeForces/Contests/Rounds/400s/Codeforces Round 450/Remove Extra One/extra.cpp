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


class SegmentTree
{
public:
	int* st;
	int* a;
	int length;
	SegmentTree(int arr[], int n)
	{
		length = n;
		a = arr;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
		build(0, 0, length - 1);
	}
	int f(int x, int y) // change for different problems
	{
		if (a[x] > a[y]) return x;
		return y;
	}
	void build(int node, int l, int r)
	{
		if (l == r)
			st[node] = l;
		else
		{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
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

int a[100005];
bool isrecord[100005];
int enable[100005];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	SegmentTree st(a, n);
	int m = 0;
	int records = 0;
	FOR(i, 0, n) {
		if (a[i] > m) {
			isrecord[i] = true;
			records++;
		}
		m = max(m, a[i]);
	}
	FOR(i, 1, n) {
		int m = st.query(0, i - 1);
		if (a[m] > a[i]) {
			bool e = true;
			if (m - 1 >= 0 && a[st.query(0, m - 1)] > a[i]){
				e = false;
			}
			if (m + 1 <= i - 1 && a[st.query(m + 1, i - 1)] > a[i]) {
				e = false;
			}
			if (e) {
				enable[m]++;
			}
		}
	}
	pii ans = { 0, 0 };
	FOR(i, 0, n) {
		int x = records - isrecord[i] + enable[i];
		ans = max(ans, {x, INF - a[i]});
	}
	cout << INF - ans.second << endl;
}