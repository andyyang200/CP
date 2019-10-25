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
struct Node {
	int val;
	struct Node* C[2];
	Node() {
		val = 0;
		C[0] = C[1] = NULL;
	}
	Node* getc(int c) {
		if (!C[c]) {
			C[c] = new Node;
		}
		return C[c];
	}
	void update(int x, int v, int sl, int sr) {
		val += v;
		if (sl == sr) {
			return;
		}
		int m = (sl + sr) / 2;
		if (x < m) {
			getc(0)->update(x, v, sl, m);
		}
		else {
			getc(1)->update(x, v, m + 1, sr);
		}
	}
	int query(int a, int b, int sl, int sr) {
		if (a <= sl && sr <= b) {
			return val;
		}
		else if (sr <= a || b <= sl) {
			return 0;
		}
		int md = (sl + sr) / 2;
		return (C[0] ? C[0]->query(a, b, sl, md) : 0) +
			(C[1] ? C[1]->query(a, b, md, sr) : 0);
	}
};
class SegmentTree
{
public:
	Node* st;
	int length;
	SegmentTree(int n)
	{
		length = n;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new Node[maxSize];
	}
	int f(int a, int b)
	{
		return a + b;
	}
	void update(int node, int sl, int sr, int x, int y, int v)
	{
		if (x < sl || x > sr)
			return;
		if (sl == sr)
		{
			st[node].update(y, v, 0, length);
		}
		if (sl != sr)
		{
			int mid = (sl + sr) / 2;
			update(node * 2 + 1, sl, mid, x, y, v);
			update(node * 2 + 2, mid + 1, sr, x, y, v);
		}
	}

	int query(int node, int sl, int sr, int x1, int x2, int y1, int y2)
	{
		if (sl > x2 || sr < x1)
			return 0;
		if (sl >= x1 && sr <= x2)
			return st[node].query(y1, y2, 0, length);
		int mid = (sl + sr) / 2;
		int a = query(node * 2 + 1, sl, mid, x1, x2, y1, y2);
		int b = query(node * 2 + 2, mid + 1, sr, x1, x2, y1, y2);
		return f(a, b);
	}
};
int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
}