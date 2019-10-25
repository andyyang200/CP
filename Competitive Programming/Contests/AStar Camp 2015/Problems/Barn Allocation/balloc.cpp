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
#include <map>
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
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int arr[100001];
int tree[300001];
int lazy[300001];

/**
* Build and init tree
*/
void build_tree(int node, int a, int b) {
	if (a > b) return; // Out of range

	if (a == b) { // Leaf node
		tree[node] = arr[a]; // Init value
		return;
	}

	build_tree(node * 2 + 1, a, (a + b) / 2); // Init left child
	build_tree(node * 2 + 2, 1 + (a + b) / 2, b); // Init right child

	tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]); // Init root value
}

/**
* Increment elements within range [i, j] with value value
*/
void update_tree(int node, int a, int b, int i, int j, int value) {

	if (lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if (a != b) {
			lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
			lazy[node * 2 + 2] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if (a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

	if (a >= i && b <= j) { // Segment is fully within range
		tree[node] += value;

		if (a != b) { // Not leaf node
			lazy[node * 2 + 1] += value;
			lazy[node * 2 + 2] += value;
		}

		return;
	}

	update_tree(node * 2 + 1, a, (a + b) / 2, i, j, value); // Updating left child
	update_tree(2 + node * 2, 1 + (a + b) / 2, b, i, j, value); // Updating right child

	tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]); // Updating root with max value
}

/**
* Query tree to get max element value within range [i, j]
*/
int query_tree(int node, int a, int b, int i, int j) {

	if (a > b || a > j || b < i) return INF; // Out of range

	if (lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if (a != b) {
			lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
			lazy[node * 2 + 2] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if (a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node * 2 + 1, a, (a + b) / 2, i, j); // Query left child
	int q2 = query_tree(2 + node * 2, 1 + (a + b) / 2, b, i, j); // Query right child

	int res = min(q1, q2); // Return final result

	return res;
}
struct Request
{
	int a, b;
	bool operator<(const Request& r) const
	{
		if (b != r.b)
		{
			return b < r.b;
		}
		return a > r.a;
	}
};
Request requests[100001];
int main()
{
	freopen("balloc.in", "r", stdin);
	freopen("balloc.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n)
	{
		scanf("%d", &arr[i]);
	}
	FOR(i, 0, m)
	{
		scanf("%d%d", &requests[i].a, &requests[i].b);
		requests[i].a--;
		requests[i].b--;
	}
	sort(requests, requests + m);
	build_tree(0, 0, n - 1);
	int ans = 0;
	FOR(i, 0, m)
	{
		int a = requests[i].a;
		int b = requests[i].b;
		int x = query_tree(0, 0, n - 1, a, b);
		if (x > 0)
		{
			ans++;
			update_tree(0, 0, n - 1, a, b, -1);
		}
	}
	cout << ans << endl;
}