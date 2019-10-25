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
struct person
{
	int number;
	string contacts;
	int guess;
	int removed;
};
person p[105];
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		p[i].number = i + 1;
		cin >> p[i].contacts;
	}
	FOR(i, 0, n)
	{
		cin >> p[i].guess;
	}
	bool done = false;
	vector<person> ans;
	while (!done)
	{
		done = true;
		FOR(i, 0, n)
		{
			if (!p[i].removed && p[i].guess == 0)
			{
				done = false;
				p[i].removed = true;
				ans.push_back(p[i]);
				break;
			}
		}
		if (done)
		{
			break;
		}
		FOR(i, 0, ans.back().contacts.length())
		{
			if (ans.back().contacts[i] == '1')
			{
				p[i].guess--;
			}
		}
	}
	cout << ans.size() << endl;
	FOR(i, 0, ans.size())
	{
		cout << ans[i].number << " ";
	}
	cout << endl;
}