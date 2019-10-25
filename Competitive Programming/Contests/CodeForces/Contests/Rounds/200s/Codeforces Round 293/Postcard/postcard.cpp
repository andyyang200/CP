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
map<char, int> a;
map<char, int> b;
int main()
{
	string s, t;
	cin >> s >> t;
	FOR(i, 0, s.length())
	{
		a[s[i]]++;
	}
	FOR(i, 0, t.length())
	{
		b[t[i]]++;
	}
	int yay = 0;
	int whoops = 0;
	for (char i = 'a'; i <= 'z'; i++)
	{
		char j = i + 'A' - 'a';
		int count = min(a[i], b[i]);
		a[i] -= count;
		b[i] -= count;
		yay += count;
		count = min(a[j], b[j]);
		a[j] -= count;
		b[j] -= count;
		yay += count;
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		char j = i + 'A' - 'a';
		int count = min(a[i], b[j]);
		a[i] -= count;
		b[j] -= count;
		whoops += count;
		count = min(a[j], b[i]);
		a[j] -= count;
		b[j] -= count;
		whoops += count;
	}
	cout << yay << " " << whoops << endl;
}