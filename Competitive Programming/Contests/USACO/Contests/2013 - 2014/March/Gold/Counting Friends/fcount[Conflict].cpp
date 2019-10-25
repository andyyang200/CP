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
typedef long long ll;
typedef pair<int, int> pii;

int numbers[501];
multiset<int> friends;
bool check(multiset<int>& temp)
{
	bool finished = true;
	FOREACH(itr, temp)
	{
		if (*itr > 0)
		{
			finished = false;
			break;
		}
	}
	if (finished)
	{
		return true;
	}
	int maxD = *(--temp.end());
	temp.erase(--temp.end());
	vector<int> v;
	RFOREACH(itr, temp)
	{
		if (maxD == 0)
		{
			break;
		}
		v.push_back(*itr);
		maxD--;
	}
	if (maxD > 0)
	{
		return false;
	}
	FOR(i, 0, v.size())
	{
		temp.erase(--temp.end());
	}
	for (int d : v)
	{
		if (d == 0)
		{
			return false;
		}
		temp.insert(d - 1);
	}
	return check(temp);
}
int main()
{
	freopen("fcount.in", "r", stdin);
	freopen("fcount.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int total = 0;
	FOR(i, 0, n + 1)
	{
		scanf("%d", &numbers[i]);
		friends.insert(numbers[i]);
		total += numbers[i];
	}
	vector<int> answer;
	FOR(i, 0, n + 1)
	{
		multiset<int> temp = friends;
		temp.erase(temp.find(numbers[i]));
		if ((total - numbers[i]) % 2 == 0 && check(temp))
		{
			answer.push_back(i + 1);
		}
	}
	cout << answer.size() << endl;
	for (int i : answer)
	{
		cout << i << endl;
	}
}