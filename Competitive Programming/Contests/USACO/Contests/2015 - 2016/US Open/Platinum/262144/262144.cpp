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
stack<vector<int>*> s;
int answer = 0;

void solve()
{
	vector<int>* c = s.top();
	s.pop();
	if (c->empty())
		return;
	if (c->size() == 1)
	{
		answer = max(answer, (*c)[0]);
		return;
	}
	int minC = INT_MAX;
	FOR(i, 0, c->size())
	{
		minC = min((*c)[i], minC);
	}
	int start = -1;
	int end = c->size();
	vector<pair<int, int>> g;
	FOR(i, 0, c->size())
	{
		if ((*c)[i] == minC && start == -1)
		{
			start = i;
		}
		if (start != -1 && (*c)[i] != minC)
		{
			end = i;
			g.push_back(make_pair(start, end));
			start = -1;
			end = c->size();
		}
	}
	if (start != -1 && end == c->size())
	{
		g.push_back(make_pair(start, end));
	}
	int index = g.size() / 2;
	start = g[index].first;
	end = g[index].second;
	if (start == end - 1)
	{
		int ans = 0;
		if (start != 0)
		{
			vector<int>* left = new vector<int>();
			left->assign(c->begin(), c->begin() + start);
			s.push(left);
		}
		if (start != c->size() - 1)
		{
			vector<int>* right = new vector<int>();
			right->assign(c->begin() + start + 1, c->end());
			s.push(right);
		}
		return;
	}
	else{
		if ((end - start) % 2 == 0)
		{
			vector <int>* nc = new vector<int>();
			nc->assign(c->begin(), c->begin() + start);
			FOR(i, 0, (end - start) / 2)
			{
				nc->push_back(minC + 1);
			}
			nc->insert(nc->end(), c->begin() + end, c->end());
			s.push(nc);
		}
		else
		{
			vector<int>* left = new vector<int>();
			left->assign(c->begin(), c->begin() + start);
			s.push(left);
			vector <int>* right = new vector<int>();
			FOR(i, 0, (end - start) / 2)
			{
				right->push_back(minC + 1);
			}
			right->insert(right->end(), c->begin() + end, c->end());
			s.push(right);

			left = new vector<int>();
			left->assign(c->begin(), c->begin() + start);
			FOR(i, 0, (end - start) / 2)
			{
				left->push_back(minC + 1);
			}
			s.push(left);
			right = new vector<int>();
			right->assign(c->begin() + end, c->end());
			s.push(right);
			return;
		}
	}
}
int main()
{
	freopen("262144.in", "r", stdin);
	freopen("262144.out", "w", stdout);
	int n;
	vector<int> c;
	cin >> n;
	c.resize(n);
	FOR(i, 0, n)
	{
		cin >> c[i];
	}
	s.push(&c);
	while (!s.empty())
	{
		solve();
	}
	cout << answer << endl;
}