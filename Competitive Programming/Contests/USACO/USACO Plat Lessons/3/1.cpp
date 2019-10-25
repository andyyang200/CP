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

//Given a tree, for each node, print how many nodes in its subtree with distance at most K from it, (N <= 100000)

class SegmentTree
{
public:
	pii* st;
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
	pii f(pii a, pii b) // change for different problems
	{
		return min(a, b);
	}
	void build(int node, int l, int r)
	{
		if (l == r)
			st[node] = {a[l], l};
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

	pii query(int ql, int qr)
	{
		return query(0, 0, length - 1, ql, qr);
	}
	pii query(int node, int sl, int sr, int ql, int qr)
	{
		if (sl > qr || sr < ql)
			return {-1, -1};
		if (sl >= ql && sr <= qr)
			return st[node];
		int mid = (sl + sr) / 2;
		int a = query(node * 2 + 1, sl, mid, ql, qr);
		int b = query(node * 2 + 2, mid + 1, sr, ql, qr);
		return f(a, b);
	}
};

int a[100005];
int value[100005];
int first[100005];
int second[100005];
int c = 0;
void dfs(int u, int p, int d){
	id[u] = c;
	a[c] = value[u];
	first[u] = c;
	c++;
	for(int v: adj[u]){
		if (v == p) continue;
		dfs(v, u, p + 1);
	}
	a[c] = value[u];
	second[u] = c;
	c++;
}
SegmentTree st;
void initLCA(){
	dfs(0, -1, 0);
	st = SegmentTree(depth, n);
}

int getMin(int a){
	return st.query(first[i], second[i]);
}

int main(void)
{

}


