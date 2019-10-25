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
map<string, int> m;
int main(void)
{
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);
	int n;
	scanf("%d", &n);
	m["Bessie"] = 0;
	m["Elsie"] = 0;
	m["Daisy"] = 0;
	m["Gertie"] = 0;
	m["Annabelle"] = 0;
	m["Maggie"] = 0;
	m["Henrietta"] = 0;
	FOR(i, 0, n)
	{
		string s;
		int x;
		cin >> s >> x;
		m[s] += x;
	}
	vector<pair<int, string>> v;
	int x = INF;
	FOREACH(itr, m)
	{
		v.push_back({itr->second, itr->first});
		x = min(x, itr->second);
	}
	if (m.size() < 7)
	{
		x = 0;
	}
	sort(v.begin(), v.end());
	FOR(i, 1, v.size())
	{
		if (v[i - 1].first == x && v[i].first > x && (i == v.size() - 1 || v[i + 1].first > v[i].first))
		{
			cout << v[i].second << endl; 
			return 0;
		}
	}
	cout << "Tie" << endl;
}