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
set<int> edges[26];
bool visited[26];
int nxt[26];
int previous[26];
string order;
int main()
{
	int n;
	scanf("%d", &n);
	string s;
	FOR(i, 0, 26)
	{
		visited[i] = true;
		nxt[i] = -1;
		previous[i] = -1;
	}
	int len = 0;
	FOR(i, 0, n)
	{
		cin >> s;
		FOR(j, 0, s.length())
		{
			visited[s[j] - 'a'] = false;
			len++;
		}
		FOR(j, 0, s.length() - 1)
		{
			nxt[s[j] - 'a'] = s[j + 1] - 'a';
			previous[s[j + 1] - 'a'] = s[j] - 'a';
		}
	}
	FOR(i, 0, 26)
	{
		if (!visited[i] && previous[i] == -1)
		{
			int j = i;
			while (j != -1 && !visited[j])
			{
				order += (char)(j + 'a');
				visited[j] = true;
				j = nxt[j];
			}
		}
	}
	cout << order << endl;
}