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

vector<pii> edgesB[100];
vector<pii> edgesE[100];
int n, m;
set<int> b;
set<int> e;
struct state
{
	int node, cost;
	bool bessie;
	state(int a, int b, bool c)
	{
		node = a;
		cost = b;
		bessie = c;
	}
};
bool compare(state a, state b)
{
	return (a.cost>b.cost);
}

void bfs()
{
	priority_queue<state, vector<state>, function<bool(state, state)> > q(compare);
	q.push(state(0, 0, true));
	q.push(state(0, 0, false));
	while (!q.empty())
	{
		state s = q.top();
		q.pop();
		if (s.bessie)
		{
			if (s.node == n)
			{
				b.insert(s.cost);
				if (find(e.begin(), e.end(), s.cost) != e.end())
				{
					cout << s.cost << endl;
					return;
				}
				continue;
			}
			for (pii p : edgesB[s.node])
			{
				q.push(state(p.first, s.cost + p.second, s.bessie));
			}
		}
		else
		{
			if (s.node == n)
			{
				e.insert(s.cost);
				if (find(b.begin(), b.end(), s.cost) != b.end())
				{
					cout << s.cost << endl;
					return;
				}
				continue;
			}
			for (pii p : edgesE[s.node])
			{
				q.push(state(p.first, s.cost + p.second, s.bessie));
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main()
{
	freopen("meeting.in", "r", stdin);
	freopen("meeting.out", "w", stdout);
	cin >> n >> m;
	n--;
	FOR(i, 0, m)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--;
		b--;
		edgesB[a].push_back(pii(b, c));
		edgesE[a].push_back(pii(b, d));
	}
	bfs();
}
