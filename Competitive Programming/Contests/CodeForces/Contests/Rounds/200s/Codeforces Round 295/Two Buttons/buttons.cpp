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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;
bool visited[10000000];
int main()
{
	int n, m;
	cin >> n >> m;
	queue<pii> q;
	q.push(pii(n, 0));
	while (!q.empty())
	{
		int x = q.front().first;
		int steps = q.front().second;
		q.pop();
		if (x == m)
		{
			cout << steps << endl;
			break;
		}
		if (x - 1 > 0 && !visited[x - 1])
		{
			q.push(pii(x - 1, steps + 1));
			visited[x - 1] = true;
		}
		if (2 * x < 10000000 && !visited[2 * x])
		{
			q.push(pii(2 * x, steps + 1));
			visited[2 * x] = true;
		}
	}
}