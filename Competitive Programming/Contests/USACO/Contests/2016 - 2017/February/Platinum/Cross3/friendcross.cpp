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
int n, k; 
struct Node
{
	int value;
	Node* left;
	Node* right;
	int height, size;
	Node()
	{
		value = -1;
		left = NULL;
		right = NULL;
		height = 0;
		size = 0;
	}
	Node(int v)
	{
		value = v;
		left = NULL;
		right = NULL;
		height = 1;
		size = 1;
	}
};
int getHeight(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
int getSize(Node* N)
{
	if (N == NULL)
		return 0;
	return N->size;
}

void updateHeight(Node* N)
{
	N->height = max(getHeight(N->left), getHeight(N->right)) + 1;
}
void updateSize(Node* N)
{
	N->size = getSize(N->left) + getSize(N->right) + 1;
}

Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	updateHeight(y);
	updateSize(y);
	updateHeight(x);
	updateSize(x);

	return x;
}

Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	updateHeight(x);
	updateSize(x);
	updateHeight(y);
	updateSize(y);

	return y;
}

int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return getHeight(N->left) - getHeight(N->right);
}

Node* insert(Node* node, int value)
{
	if (node == NULL)
		return new Node(value);

	if (value <= node->value)
		node->left = insert(node->left, value);
	else if (value > node->value)
		node->right = insert(node->right, value);

	updateHeight(node);
	updateSize(node);
	int balance = getBalance(node);

	// Left Left Case
	if (balance > 1 && value <= node->left->value)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && value > node->right->value)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && value > node->left->value)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && value <= node->right->value)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	//unchanged
	return node;
}
int query(Node* N, int x)
{
	if (N == NULL)
	{
		return 0;
	}
	if (N->value >= x)
	{
		return 1 + getSize(N->right) + query(N->left, x);
	}
	else
	{
		return query(N->right, x);
	}
}

Node* BIT[100001];
void buildBIT( int n)
{
	FOR(i, 1, n + 1)
		BIT[i] = new Node();
}
void updateBIT(int i, int v)
{
	++i;
	while (i <= n)
	{
		BIT[i] = insert(BIT[i], v);
		i += i & (-i);
	}
}
int queryBIT(int i, int v)
{
	int sum = 0;
	++i;
	while (i > 0)
	{
		sum += query(BIT[i], v);
		i -= i & (-i);
	}
	return sum;
}
int st[600000];
void updateST(int node, int sl, int sr, int i, int v)
{
	if (i < sl || i > sr)
		return;
	st[node] += v;
	if (sl != sr)
	{
		int mid = (sl + sr) >> 1;
		updateST((node << 1) + 1, sl, mid, i, v);
		updateST((node << 1) + 2, mid + 1, sr, i, v);
	}
}

int queryST(int node, int sl, int sr, int ql, int qr)
{
	if (sl > qr || sr < ql)
		return 0;
	if (sl >= ql && sr <= qr)
		return st[node];
	int mid = (sl + sr) >> 1;
	return queryST((node << 1) + 1, sl, mid, ql, qr) + queryST((node << 1) + 2, mid + 1, sr, ql, qr);
}
int top[100000];
int bottomLocation[100000];
int query(int l, int r, int v1, int v2)
{	
	int a = queryBIT(r, v1) - (l > 0 ? queryBIT(l - 1, v1) : 0);
	int b = queryBIT(r, v2 + 1) - (l > 0 ? queryBIT(l - 1, v2 + 1) : 0);
	return a - b;
}
int main(void)
{
	freopen("friendcross.in", "r", stdin);
	freopen("friendcross.out", "w", stdout);
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		scanf("%d", &top[i]);
		--top[i];
	}
	FOR(i, 0, n)
	{
		int b;
		scanf("%d", &b);
		bottomLocation[b - 1] = i;
	}
	ll friendly = 0;
	ll crosses = 0;
	buildBIT(n);
	FOR(i, 0, n)
	{
		crosses += queryST(0, 0, n - 1, bottomLocation[top[i]], n - 1);
		updateST(0, 0, n - 1, bottomLocation[top[i]], 1);
		friendly += query(bottomLocation[top[i]] + 1, n - 1, max(0, top[i] - k), min(n - 1, top[i] + k));
		updateBIT(bottomLocation[top[i]], top[i]);
	}
	printf("%lld\n", crosses - friendly);
}
