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
#define eps 0.000001
#define precision 1000
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> trees;
int ans[301];
pii root;
struct node
{
	double val;
	int cnt;
	struct node* C[2];
	node()
	{
		val = -1;
		cnt = 0;
		C[0] = C[1] = NULL;
	}

	node* getc(int c)
	{
		if (!C[c])
		{
			C[c] = new node;
		}
		return C[c];
	}
	void add(double x)
	{
		if (val == -1)
		{
			val = x;
			cnt = 1;
			return;
		}
		else if (x <= val)
		{
			getc(0)->add(x);
			cnt++;
		}
		else
		{
			getc(1)->add(x);
		}
	}
	int query(double x)
	{
		if (val == -1)
		{
			return 0;
		}
		else if (x <= val)
		{
			return getc(0)->query(x);
		}
		else
		{
			return cnt + getc(1)->query(x);
		}
	}
};

double slope(pii& a, pii& b)
{
	if (a.first == b.first)
	{
		return INF;
	}
	return (double)(a.second - b.second) / (a.first - b.first);
}
bool pointCompare(pii a, pii b)
{
	double m1 = slope(root, a);
	double m2 = slope(root, b);
	return m1 > m2;
}
double dot(pii x, pii y)
{
	return (double)x.first * y.first + (double)x.second * y.second;
}
double magnitude(pii x)
{
	return sqrt((double)x.first * x.first + (double)x.second * x.second);
}

void work(int x)
{
	sort(trees.begin(), trees.end(), pointCompare);
	FOR(i, 0, trees.size())
	{
		node x = node();
		FOR(j, i + 1, trees.size())
		{
			pii u = { root.first - trees[i].first, root.second - trees[i].second };
			pii v = { trees[j].first - trees[i].first, trees[j].second - trees[i].second };
			double ac = 1 / (dot(u, v) / (magnitude(u) * magnitude(v)) + 1.1);
			ans[x.query(ac)]++;
			x.add(ac);
		}
	}
}

int getMinTree()
{
	root = { INF, INF };
	int ret = -1;
	FOR(i, 0, trees.size())
	{
		pii t = trees[i];
		if (t.first < root.first || (t.first == root.first && t.second < root.second))
		{
			root = t;
			ret = i;
		}
	}
	return ret;
}

int main(void)
{
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		pii tree;
		scanf("%d%d", &tree.first, &tree.second);
		trees.push_back(tree);
	}
	while (trees.size() >= 3)
	{
		int i = getMinTree();
		trees.erase(trees.begin() + i);
		work(i);
	}
	FOR(i, 0, n - 2)
	{
		cout << ans[i] << endl;
	}
}