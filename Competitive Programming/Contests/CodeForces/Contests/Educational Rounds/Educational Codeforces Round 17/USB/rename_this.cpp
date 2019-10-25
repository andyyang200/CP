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
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int m;
	scanf("%d", &m);
	vector<int> USB;
	vector<int> PS;
	FOR(i, 0, m)
	{
		int p;
		scanf("%d", &p);
		string s;
		cin >> s;
		char c = s[0];
		if (c == 'U')
		{
			USB.push_back(p);
		}
		else
		{
			PS.push_back(p);
		}
	}
	sort(USB.rbegin(), USB.rend());
	sort(PS.rbegin(), PS.rend());
	int ans1 = 0;
	ll ans2 = 0;
	while (a > 0 && USB.size() > 0)
	{
		ans1++;
		ans2 += USB.back();
		USB.pop_back();
		a--;
	}
	while (b > 0 && PS.size() > 0)
	{
		ans1++;
		ans2 += PS.back();
		PS.pop_back();
		b--;
	}
	FOR(i, 0, PS.size())
	{
		USB.push_back(PS[i]);
	}
	sort(USB.rbegin(), USB.rend());
	while (c > 0 && USB.size() > 0)
	{	
		ans1++;
		ans2 += USB.back();
		USB.pop_back();
		c--;
	}
	cout << ans1 << " " << ans2 << endl;
}