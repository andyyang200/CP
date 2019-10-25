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
int match[1000001];
string s;
bool open(int i)
{
	return s[i] == '<' || s[i] == '{' || s[i] == '[' || s[i] == '(';
}
int main()
{
	cin >> s;
	stack<int> st;
	FOR(i, 0, s.length())
	{
		if (open(i))
		{
			st.push(i);
		}
		else
		{
			if (st.size() == 0)
			{
				cout << "Impossible" << endl;
				return 0;
			}
			match[i] = st.top();
			st.pop();
		}
	}
	if (st.size() != 0)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	int ans = 0;
	FOR(i, 0, s.length())
	{
		if (s[i] == '>' && s[match[i]] != '<')
		{
			ans++;
		}
		if (s[i] == '}' && s[match[i]] != '{')
		{
			ans++;
		}
		if (s[i] == ']' && s[match[i]] != '[')
		{
			ans++;
		}
		if (s[i] == ')' && s[match[i]] != '(')
		{
			ans++;
		}
	}
	cout << ans << endl;
}