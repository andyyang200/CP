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
map<string, bool> used;
int compare(string a, string b)
{
	if (a.length() != b.length())
	{
		return a.length() - b.length();
	}
	int n = a.compare(b);
	return n;
}
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		string s;
		cin >> s;
		s = s.substr(4, 100);
		if (!used[s] && compare(s, "1989") >= 0)
		{
			used[s] = true;
			cout << s << endl;
			continue;
		}
		int a = 1;
		stringstream ss;
		ss << a;
		string t = ss.str() + s;
		while (used[t] || compare(t, "1989") < 0)
		{
			a++;
			stringstream ss;
			ss << a;
			t = ss.str() + s;
		}
		cout << t << endl;
		used[t] = true;
	}
}