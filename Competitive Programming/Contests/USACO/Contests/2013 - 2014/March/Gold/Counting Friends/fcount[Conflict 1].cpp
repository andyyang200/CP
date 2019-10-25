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
vector<int> v(500);

bool check(multiset<int>& temp)
{
	if (*temp.rbegin() == 0)
		return true;

	int maxD = *(temp.rbegin());
	temp.erase(prev(temp.end()));
	if (maxD > temp.size())
		return false;
	v.clear();
	FOR(i,0, maxD)
	{
		v.push_back(*temp.rbegin());
		temp.erase(prev(temp.end()));
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
	freopen("5.in", "r", stdin);
	//freopen("fcount.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int tsum = 0;
	FOR(i, 0, n + 1)
	{
		scanf("%d", &numbers[i]);
		friends.insert(numbers[i]);
		tsum += numbers[i];
	}
	vector<int> answer;
	map<int, bool> answers;

	FOR(i, 0, n + 1)
	{
		if ((tsum - numbers[i]) % 2 == 1)
			continue;
		if (answers.find(numbers[i]) != answers.end())
		{
			if (answers[numbers[i]])
			{
				answer.push_back(i + 1);
			}
		}
		else
		{
			multiset<int> temp = friends;
			temp.erase(temp.find(numbers[i]));
			if (check(temp))
			{
				answer.push_back(i + 1);
				answers[numbers[i]] = true;
			}
			else
			{
				answers[numbers[i]] = false;
			}
		}
	}
	cout << answer.size() << endl;
	for (int i : answer)
	{
		cout << i << endl;
	}
}