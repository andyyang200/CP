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
bool contains[10];
int main(void)
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	FOR(i, 0, n)
	{
		contains[s[i] - '0'] = true;
	}
	if (!contains[1] && !contains[4] && !contains[7] && !contains[0])
	{
		cout << "NO" << endl;
		return 0;
	}
	if (!contains[3] && !contains[6] && !contains[9] && !contains[0])
	{
		cout << "NO" << endl;
		return 0;
	}
	if (!contains[7] && !contains[0] && !contains[9])
	{
		cout << "NO" << endl;
		return 0;
	}
	if (!contains[1] && !contains[2] && !contains[3])
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
}