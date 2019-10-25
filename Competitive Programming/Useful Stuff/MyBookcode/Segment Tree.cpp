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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;
#define INF 1000000000

class SegmentTree{
public:
	int* st;
	int* a;
	int length;
	SegmentTree(int arr[], int n){
		length = n;
		a = arr;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
		build(0, 0, length - 1);
	}
	int f(int a, int b){// change for different problems
		return max(a, b);
	}
	void build(int node, int l, int r){
		if (l == r)
			st[node] = a[l];
		else{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	void update(int i, int v){
		update(0, 0, length - 1, i, v);
		a[i] = v;
	}
	void update(int node, int sl, int sr, int i, int v)
	{
		if (i < sl || i > sr)
			return;
		if (sl == sr){
			st[node] = v;
		}
		if (sl != sr){
			int mid = (sl + sr) / 2;
			update(node * 2 + 1, sl, mid, i, v);
			update(node * 2 + 2, mid + 1, sr, i, v);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	int query(int ql, int qr){
		return query(0, 0, length - 1, ql, qr);
	}
	int query(int node, int sl, int sr, int ql, int qr){
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

int main(){

}
