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

int val[26];
map<pair<ll, char>, int> m;
int main()
{
	FOR(i, 0, 26)
	{
		cin >> val[i];
	}
	string s;
	cin >> s;
	ll ans = 0;
	ll sum = 0;
	FOR(i, 0, s.length())
	{
		ans += m[make_pair(sum, s[i])];
		sum += val[s[i] - 'a'];
		m[make_pair(sum, s[i])]++;
	}
	cout << ans << endl;
}