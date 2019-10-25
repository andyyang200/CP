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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	string s;
	cin >> s;
	FOR(i, 0, s.length())
	{
		if (s[i] % 8 == 0)
		{
			cout << "YES" << endl;
			cout << s[i] << endl;
			return 0;
		}
		FOR(j, i + 1, s.length())
		{
			if ((10 * (s[i] - '0') + (s[j] - '0')) % 8 == 0)
			{
				cout << "YES" << endl;
				cout << s[i] << s[j] << endl;
				return 0;
			}
			FOR(k, j + 1, s.length())
			{
				if ((100 * (s[i] - '0') + 10 * (s[j] - '0') + s[k] - '0') % 8 == 0)
				{
					cout << "YES" << endl;
					cout << s[i] << s[j] << s[k] << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
}