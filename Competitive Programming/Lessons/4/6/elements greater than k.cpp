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
	vector<int>* st;
	int* a;
	int length;
	SegmentTree(int arr[], int n)
	{
		length = n;
		a = arr;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new vector<int>[maxSize];
		build(0, 0, length - 1);
	}
	int f(int a, int b)
	{
		return max(a, b);
	}
	void build(int node, int l, int r)
	{
		FOR(i, l, r + 1)
		{
			st[node].push_back(a[i]);
		}
		sort(st[node].begin(), st[node].end());
		if (l != r)
		{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
		}
	}

	int query(int ql, int qr, int k)
	{
		return query(0, 0, length - 1, ql, qr, k);
	}
	int query(int node, int sl, int sr, int ql, int qr, int k)
	{
		if (sl > qr || sr < ql)
			return -1;
		if (sl >= ql && sr <= qr)
			return st[node].end() - lower_bound(st[node].begin(), st[node].end(), k);
		int mid = (sl + sr) / 2;
		int a = query(node * 2 + 1, sl, mid, ql, qr,  k);
		int b = query(node * 2 + 2, mid + 1, sr, ql, qr, k);
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