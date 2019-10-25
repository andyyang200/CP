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
#include <limits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

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
		return a + b;
	}
	void build(int node, int l, int r)
	{
		st[node] = 0;
		if (l == r)
			return;
		int mid = (l + r) / 2;
		build(node * 2 + 1, l, mid);
		build(node * 2 + 2, mid + 1, r);
	}

	void update(int i, int v)
	{
		update(0, 0, length - 1, i, v);
	}
	void update(int node, int sl, int sr, int i, int v)
	{
		if (i < sl || i > sr)
			return;
		st[node] = f(st[node], v);
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

int top[100001];
int bottom[100001];
int topLocation[100001];
int bottomLocation[100001];
int ans;
void generateData(int n)
{
	FOR(i, 0, n)
	{
		top[i] = i;
		bottom[i] = i;
	}
	int s = rand() % (n*n);
	FOR(i, 0, s)
		next_permutation(top, top + n);
	s = rand() % (n*n);
	FOR(i, 0, s)
		next_permutation(bottom, bottom + n);
	FOR(i, 0, n)
	{
		topLocation[top[i]] = i;
		bottomLocation[bottom[i]] = i;
	}

}

int CalcCross(int n)
{
	int cross = 0;
	FOR(i, 0, n - 1)
		FOR(j, i + 1, n)
	{
		if (bottomLocation[top[i]] > bottomLocation[top[j]])
		{
			cross++;
		}
	}
	return cross;
}
int bash(int n)
{
	int minCross = INT_MAX;
	FOR(shift, 0, n)
	{
		// shift top array 1 pos to the left
		int cross = CalcCross(n);
		minCross = min(minCross, cross);

		int temp = top[0];
		memcpy(top, top + 1, sizeof(int) * (n - 1));
		top[n - 1] = temp;

	}
	return minCross;
}

int main(void)
{
	srand((unsigned)time(NULL));
	//freopen("mincross.in", "r", stdin);
	//freopen("mincross.out", "w", stdout);

	int n;
	scanf("%d", &n);
	vector<int> t, b;
	//generateData(n);
	FOR(i, 0, n)
	{
		scanf("%d", &top[i]);
		top[i]--;
		topLocation[top[i]] = i;
	}
	FOR(i, 0, n)
	{
		scanf("%d", &bottom[i]);
		bottom[i]--;
		bottomLocation[bottom[i]] = i;
	}
	cout << "bash returns " << bash(n) << endl;
	ll crosses = 0;
	SegmentTree st(n);
	FOR(i, 0, n)
	{
		crosses += st.query(bottom[top[i]], n - 1);
		st.update(bottom[top[i]], 1);
	}
	st = SegmentTree(n);
	RFOR(i, n - 1, -1)
	{
		crosses += st.query(0, bottom[top[i]]);
		st.update(bottom[top[i]], 1);
	}
	crosses /= 2;
	ll ans = crosses;
	RFOR(i, n - 1, -1)
	{
		crosses -= n - bottom[i] - 1;
		crosses += bottom[i];
		ans = min(ans, crosses);
	}
	RFOR(i, n - 1, -1)
	{
		crosses -= n - top[i] - 1;
		crosses += top[i];
		ans = min(ans, crosses);
	}
	cout << "ans: " << ans << endl;
	cout << "bash: " << bash() << endl;
}
/*
4
1
4
2
3
4
3
1
2
*/

/*
2
*/
