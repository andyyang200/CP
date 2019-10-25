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
#include <unordered_map>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;

set<pair<int, pii>> canRemove;
map < pii, int > cubes;
vector<int> answer;
int count(pii p)
{
	int x = p.first;
	int y = p.second;
	int sum = 0;
	if (cubes[{x - 1, y - 1}] != 0)
	{
		sum++;
	}
	if (cubes[{x, y - 1}] != 0)
	{
		sum++;
	}
	if (cubes[{x + 1, y - 1}] != 0)
	{
		sum++;
	}
	return sum;
}
int canBeRemoved(pii p)
{
	int x = p.first;
	int y = p.second;
	if (cubes[{x - 1, y + 1}] != 0 && count({ x - 1, y + 1 }) == 1)
	{
		return false;
	}
	if (cubes[{x, y + 1}] != 0 && count({ x, y + 1 }) == 1)
	{
		return false;
	}
	if (cubes[{x + 1, y + 1}] != 0 && count({ x + 1, y + 1 }) == 1)
	{
		return false;
	}
	return true;
}
void update(pii p)
{
	int x = p.first;
	int y = p.second;
	if (cubes[{x - 2, y}] != 0 && !canBeRemoved({ x - 2, y }))
	{
		auto itr = canRemove.find({ cubes[{x - 2, y}], { x - 2, y } });
		if (itr != canRemove.end())
		{
			canRemove.erase(itr);
		}
	}
	if (cubes[{x - 1, y}] != 0 && !canBeRemoved({ x - 1, y }))
	{
		auto itr = canRemove.find({ cubes[{x - 1, y}], { x - 1, y } });
		if (itr != canRemove.end())
		{
			canRemove.erase(itr);
		}
	}
	if (cubes[{x + 1, y}] != 0 && !canBeRemoved({ x + 1, y }))
	{
		auto itr = canRemove.find({ cubes[{x + 1, y}], { x + 1, y } });
		if (itr != canRemove.end())
		{
			canRemove.erase(itr);
		}
	}
	if (cubes[{x + 2, y}] != 0 && !canBeRemoved({ x + 2, y }))
	{
		auto itr = canRemove.find({ cubes[{x + 2, y}], { x + 2, y } });
		if (itr != canRemove.end())
		{
			canRemove.erase(itr);
		}
	}
	if (cubes[{x - 1, y - 1}] != 0 && canBeRemoved({ x - 1, y - 1 }))
	{
		canRemove.insert({cubes[{x - 1, y - 1}] ,  { x - 1, y - 1 }});
	}
	if (cubes[{x, y - 1}] != 0 && canBeRemoved({ x, y - 1 }))
	{
		canRemove.insert({ cubes[{x, y - 1}], { x, y - 1 } });
	}
	if (cubes[{x + 1, y - 1}] != 0 && canBeRemoved({ x + 1, y - 1 }))
	{
		canRemove.insert({ cubes[{x + 1, y - 1}], { x + 1, y - 1 } });
	}
}
int main()
{
	int m;
	scanf("%d", &m);
	FOR(i, 0, m)
	{
		pii cube;
		scanf("%d%d", &cube.first, &cube.second);
		cubes[cube] = i + 1;
	}
	for (auto itr = cubes.begin(); itr != cubes.end(); itr++)
	{
		if (itr->second != 0 && canBeRemoved(itr->first))
		{
			canRemove.insert({ itr->second, itr->first });
		}
	}
	int turn = 0;
	while (answer.size() < m)
	{
		if (turn == 0)
		{
			pii p = (--canRemove.end())->second;
			answer.push_back((--canRemove.end())->first);
			cubes[p] = 0;
			canRemove.erase(--canRemove.end());
			update(p);
		}
		else
		{
			pii p = canRemove.begin()->second;
			answer.push_back(canRemove.begin()->first);
			cubes[p] = 0;
			canRemove.erase(canRemove.begin());
			update(p);
		}
		turn++;
		turn %= 2;
	}
	ll res = 0;
	ll pow = 1;
	RFOR(i, answer.size() - 1, -1)
	{
		res += (answer[i] - 1) * pow;
		pow *= m;
		pow %= 1000000009;
		res %= 1000000009;
	}
	cout << res << endl;
}