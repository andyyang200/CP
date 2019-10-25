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
typedef long long ll;
typedef pair<int, int> pii;
ll sums[100];
ll temp[100];
int main()
{
	string s, t;
	cin >> s >> t;
	FOR(i, 0, s.length())
	{
		memcpy(temp, sums, t.length() * sizeof(sums[0]));
		if (s[i] == t[0])
		{
			temp[0]++;
			temp[0] %= 1000000009;
		}
		FOR(j, 1, t.length())
		{
			if (s[i] == t[j])
			{
				temp[j] += sums[j - 1];
				temp[j] %= 1000000009;
			}
		}
		memcpy(sums, temp, t.length() * sizeof(temp[0]));
	}
	cout << sums[t.length() - 1] << endl;
}