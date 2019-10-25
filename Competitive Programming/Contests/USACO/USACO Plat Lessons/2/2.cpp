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

// Given n points in the plane (x <= 100000 y <= 10^9), support queries counting the number of points in a rectangle

map<int, vector<int>> m;
class SegmentTree
{
public:
	vector<int>* st;
	int length;
	SegmentTree()
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
		return a + b;
	}
	void build(int node, int l, int r)
	{
		for(int i = l; i <= r; i++){
			for(int y : m[i])
				st[node].push_back(y);
			sort(st[node].begin(), st[node].end());
		}
		if (l != r)
		{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
			
		}
	}

	int query(int ql, int qr)
	{
		return query(0, 0, length - 1, ql, qr);
	}
	int query(int node, int sl, int sr, int qlx, int qrx, int qly, int qry)
	{

		if (sl > qr || sr < ql)
			return -1;
		if (sl >= qlx && sr <= qrx){
			int cnt = 0;
			cnt += upper_bound(st[node].begin(), st[node].end(), qry) - lower_bound(st[node].begin(), st[node].end, qly);
			return cnt;
		}
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

