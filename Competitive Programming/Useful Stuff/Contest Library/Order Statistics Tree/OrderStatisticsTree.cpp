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
#include <unordered_set> nk
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

// Only use insert and query functions
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
int query(Node* N, int x) // currently queries number of nodes greater than x, MODIFY FOR DIFFERENT PROBLEMS
{
	if (N == NULL)
	{
		return 0;
	}
	if (N->value > x)
	{
		return 1 + getSize(N->right) + query(N->left, x);
	}
	else
	{
		return query(N->right, x);
	}
}
int main()
{
	Node *root = NULL;
	FOR(i, 0, 1000000)
	{
		root = insert(root, 1);
	}
	cout << query(root, 1) << endl;

}