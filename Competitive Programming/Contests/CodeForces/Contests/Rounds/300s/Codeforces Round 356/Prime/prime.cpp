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
int primes[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
int main(void)
{
	int cnt = 0;
	int f = 2;
	FOR(i, 0, 15)
	{
		cout << primes[i] << endl;
		fflush(stdout);
		string res = "";
		cin >> res;
		if (res == "yes")
		{
			cnt++;
			f = primes[i];
		}
	}
	if (cnt > 1)
	{
		cout << "composite" << endl;
		return 0;
	}
	if (f * f <= 100)
	{
		cout << f * f << endl;
		fflush(stdout);
		string res = "";
		cin >> res;
		if (res == "yes")
		{
			cout << "composite" << endl;
			return 0;
		}
	}
	cout << "prime" << endl;
}