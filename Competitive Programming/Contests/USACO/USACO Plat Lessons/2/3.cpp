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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

// Given a 500 by 500 grid, support queries: 1. update a grid value, and 2: find sum of values in a rectangle

class SegmentTreeInside
{
public:
	int* st;
	int* a;
	int length;
	SegmentTreeInside(int arr[], int n)
	{
		length = n;
		a = arr;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
		build(0, 0, length - 1);
	}
	int f(int a, int b) // change for different problems
	{
		return a + b
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
int grid[500][500];
int n, m;

class SegmentTreeOutside
{
public:
	SegmentTreeInside* st;
	int* a;
	int length;
	SegmentTreeOutside()
	{
		length = n;
		a = arr;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
		build(0, 0, length - 1);
	}
	void build(int node, int l, int r)
	{
		int a[m];
		for(int i = l; i <= r; i++){
			for(j = 0; j < m; j++){
				a[j] += grid[i][j];
			}
		}
		st[node] = new SegmentTreeInside(a, m);
		if (l != r)
		{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
		}
	}

	void update(int i, int v)
	{
		update(0, 0, length - 1, i, v); //if sum query last parameter should be v - a[i], otherwise should be v
		a[i] = v;
	}
	void update(int node, int sl, int sr, int i, int j, int v)
	{
		if (i < sl || i > sr) return;
		if (i <= sr && i >= sl){
			st[node].update(j, v);
		}
		if (sl != sr)
		{
			int mid = (sl + sr) / 2;
			update(node * 2 + 1, sl, mid, i, v);
			update(node * 2 + 2, mid + 1, sr, i, v);
		}
	}

	int query(int ql, int qr)
	{
		return query(0, 0, length - 1, ql, qr);
	}
	int query(int node, int sl, int sr, int qlr, int qrr, int qlc, int qrc)
	{
		if (sl > qr || sr < ql)
			return -1;
		if (sl >= ql && sr <= qr)
			return st[node].query(qlc, qrc);
		int mid = (sl + sr) / 2;
		int a = query(node * 2 + 1, sl, mid, ql, qr);
		int b = query(node * 2 + 2, mid + 1, sr, ql, qr);
		if (a == -1)
			return b;
		if (b == -1)
			return a;
		return a + b;
	}
};

int main(void)
{
	
}

