#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
#define MAX_N 300000
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


string T;

class SegmentTree
{
public:
	int* st;
	int* a;
	int length;
	SegmentTree(int arr[], int len)
	{
		length = len;
		a = arr;
		int height = (int)(ceil(log2(len)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
		build(0, 0, len - 1);
	}
	int f(int a, int b) // change for different problems
	{
		return min(a, b);
	}
	void build(int node, int l, int r)
	{
		if (l == r)
			st[node] = a[l];
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
		a[i] = v;
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

int n;

int RA[MAX_N], tempRA[MAX_N]; // 1-indexed
int SA[MAX_N], tempSA[MAX_N];

int c[MAX_N];
int lcp[MAX_N];
void constructLCP() {
	int k = 0;
	for (int i = 0; i<n; i++)
		RA[SA[i]] = i;
	for (int i = 0; i<n; i++, k ? k-- : 0) {
		if (RA[i] == n - 1) {
			k = 0;
			continue;
		}
		int j = SA[RA[i] + 1];
		while (i + k < n && j + k < n && T[i + k] == T[j + k])
			k++;
		lcp[RA[i]] = k;
	}
}
void countingSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (i = 0; i < n; i++)
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void constructSA() {
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = T[i];
	for (i = 0; i < n; i++) SA[i] = n - 1 - i;
	for (k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 1;
		for (i = 1; i < n; i++)
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (i = 0; i < n; i++)
			RA[i] = tempRA[i];
		if (RA[SA[n - 1]] == n) break;
	}
}
int main() {
	string x;
	cin >> x;
	T = x;
	T += "$";
	reverse(x.begin(), x.end());
	T += x;
	n = T.length();
	constructSA();
	constructLCP();
	SegmentTree st(lcp, T.length() + 5);
	int ans = 0;
	FOR(i, 0, n) { // odd
		int j = x.length() + (x.length() - i);
		int x = min(RA[i], RA[j]);
		int y = max(RA[i], RA[j]);
		ans = max(ans, (st.query(x, y - 1) - 1) * 2 + 1);
	}
	FOR(i, 1, n) {
		int j = x.length() + (x.length() - i + 1);
		int x = min(RA[i], RA[j]);
		int y = max(RA[i], RA[j]);
		ans = max(ans, st.query(x, y - 1) * 2);

	}
	cout << ans << endl;
}
