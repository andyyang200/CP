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
map<string, int> ways;

int count(string s)
{
	if (ways[s] != 0)
	{
		return ways[s];
	}
	int l = s.length();
	int sum = 1;
	for (int i = 1; i * 2 < l; i++) 
	{
		if (s.substr(0, i) == s.substr(l - i, i))
		{
			sum += count(s.substr(0, l - i));
			sum += count(s.substr(i, l - i));
		}
		if (s.substr(0, i) == s.substr(i, i))
		{
			sum += count(s.substr(i, l - i));
		}
		if (s.substr(l - 2 * i, i) == s.substr(l - i, i))
		{
			sum += count(s.substr(0, l - i));
		}
	}
	sum %= 2014;
	ways[s] = sum;
	return sum;

}
int main()
{
	freopen("scode.in", "r", stdin);
	freopen("scode.out", "w", stdout);
	string s;
	cin >> s;
	cout << count(s) - 1 << endl;
}