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

int main()
{
	string a;
	cin >> a;
	string x;
	cin >> x;
	reverse(x.begin(), x.end());
	a += x;
	string b;
	cin >> b;
	cin >> x;
	reverse(x.begin(), x.end());
	b += x;
	FOR(i, 0, 4)
	{
		if (a[i] == 'X')
		{
			a.erase(a.begin() + i);
		}
		if (b[i] == 'X')
		{
			b.erase(b.begin() + i);
		}
	}
	FOR(i, 0, 5)
	{
		if (a == b)
		{
			cout << "YES" << endl;
			return 0;
		}
		rotate(a.begin(), a.begin() + 1, a.end());
	}
	cout << "NO" << endl;
}