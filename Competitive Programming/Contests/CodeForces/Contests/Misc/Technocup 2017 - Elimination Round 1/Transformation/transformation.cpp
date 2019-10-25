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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
map<long, bool> vis;
map<long, int> pre;
int main(void)
{
	long a, b;
	cin >> a >> b;
	queue<long> q;
	q.push(b);
	pre[b] = -1;
	vis[b] = true;
	long ans = -1;
	while (!q.empty())
	{
		long x = q.front();
		q.pop();
		if (x < a)
		{
			continue;
		}
		if (x == a)
		{
			ans = x;
			break;
		}
		if (x % 2 == 0)
		{
			long y = x / 2;
			if (!vis[y])
			{
				vis[y] = true;
				pre[y] = x;
				q.push(y);
			}
		}
		if (x % 10 == 1)
		{
			int y = (x - 1) / 10;
			if (!vis[y])
			{
				vis[y] = true;
				pre[y] = x;
				q.push(y);
			}
		}
	}
	if (ans == -1)
	{
		cout << "NO" << endl;
		return 0;
	}
	vector<int> v;
	v.push_back(ans);
	while (pre[ans] != -1)
	{
		ans = pre[ans];
		v.push_back(ans);
	}
	cout << "YES" << endl;
	cout << v.size() << endl;
	FOR(i, 0, v.size())
	{
		cout << v[i] << " ";
	}
	cout << endl;
}