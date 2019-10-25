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
vector<int> friends;
vector<int> temp;
int n;
bool check()
{
	FOR(k, 1, n + 1)
	{
		int a = 0;
		FOR(i, 1, k + 1)
		{
			a += temp[i];
		}
		int b = k * (k - 1);
		FOR(i, k + 1, n + 1)
		{
			b += min(temp[i], k);
		}
		if (a > b)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("fcount.in", "r", stdin);
	freopen("fcount.out", "w", stdout);
	scanf("%d", &n);
	int total = 0;
	FOR(i, 1, n + 2)
	{
		scanf("%d", &numbers[i]);
		friends.push_back(numbers[i]);
		total += numbers[i];
	}
	vector<int> answer;
	FOR(i, 1, n + 2)
	{
		if ((total - numbers[i]) % 2 == 1)
		{
			continue;
		}
		temp = friends;
		temp.erase(temp.begin() + i - 1);
		sort(temp.begin(), temp.end());
		temp.push_back(0);
		reverse(temp.begin(), temp.end());
		if (check())
		{
			answer.push_back(i);
		}
	}
	cout << answer.size() << endl;
	for (int i : answer)
	{
		cout << i << endl;
	}
}