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
	int p, q, n;
	cin >> n >> p >> q;
	string s;
	cin >> s;
	int nump = -1;
	int numq = -1;
	FOR(i, 0, n)
	{
		if (i * p > s.length())
		{
			break;
		}
		if ((s.length() - i * p) % q == 0)
		{
			nump = i;
			numq = (s.length() - i * p) / q;
			break;
		}
	}
	if (nump == -1)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << nump + numq << endl;
	FOR(i, 0, nump)
	{
		cout << s.substr(0, p) << endl;
		s = s.substr(p, 100);
	}
	FOR(i, 0, numq)
	{
		cout << s.substr(0, q) << endl;
		s = s.substr(q, 100);
	}
}