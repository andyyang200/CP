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
#define M 1000000007;
#define P 257;
ll p[1000000];
vector<ll> hashes;

int main()
{
	//freopen("censor.in", "r", stdin);
	//freopen("censor.out", "w", stdout);
	string s, t;
	cin >> s >> t;
	p[0] = 1;
	FOR(i, 1, s.length())
	{
		p[i] = p[i - 1] * P;
		p[i] %= M;
	}
	string r = "";
	ll hashT = 0;
	FOR(i, 0, t.length())
	{
		hashT += p[i] * t[i];
		hashT %= M;
	}
	hashes.push_back(0);
	FOR(i, 0, s.length())
	{
		r += s[i];
		hashes.push_back(hashes[hashes.size() - 1] + p[hashes.size() - 1] * s[i]);
		hashes[hashes.size() - 1] %= M;
		if (r.length() >= t.length())
		{
			ll end = hashes[hashes.size() - 1] - hashes[hashes.size() - 1 - t.length()];
			while (end < 0)
			{
				end += M;
			}
			end *= p[hashes.size() - t.length()];
			end %= M;
			if (end == hashT)
			{
				r.erase(r.end() - t.length(), r.end());
				hashes.erase(hashes.end() - t.length(), hashes.end());
			}
		}
	}
	cout << r << endl;
}