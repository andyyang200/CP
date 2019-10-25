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
string strings[200001];
int main(void)
{
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		string a, b;
		cin >> a >> b;
		m[a.substr(0, 2) + b]++;
	}
	int ans = 0;
	FOREACH(itr, m)
	{
		string original = itr->first;
		string flip = original.substr(2, 2) + original.substr(0, 2);
		if (m.find(flip) != m.end() && original != flip)
		{
			ans+= m[flip] * m[original];
		}
	}
	cout << ans / 2 << endl;
}