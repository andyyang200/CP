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
#define M 1000000000007
typedef long long ll;
typedef pair<int, int> pii;

set<ll> hashes;
ll p[600001];

ll getHash(char s[])
{
	ll ans = 0;
	int l = strlen(s);
	FOR(i, 0, l)
	{
		ans += p[i] * (s[i] - 'a' + 1);
		ans %= M;
	}
	return ans;
}
int main()
{
	p[0] = 1;
	FOR(i, 1, 600001)
	{
		p[i] = p[i - 1] * 257;
		p[i] %= M;
	}

	int n, m;
	scanf("%d%d", &n, &m);

	char s[600001];
	FOR(i, 0, n)
	{
		scanf("%s", s);
		hashes.insert(getHash(s));
	}

	FOR(i, 0, m)
	{
		scanf("%s", s);
		bool found = false;
		int l = strlen(s);
		FOR(j, 0, l)
		{
			if (found)
			{
				break;
			}
			ll hash = getHash(s);
			for (char c = 'a'; c <= 'c'; c++)
			{
				if (c != s[j])
				{
					ll temp = hash;
					hash += p[j] * (c - 'a' + 1);
					hash %= M;
					hash -= p[j] * (s[j] - 'a' + 1);
					while (hash < 0)
					{
						hash += M;
					}
					if (hashes.find(hash) != hashes.end())
					{
						cout << "YES" << endl;
						found = true;
						break;
					}
					hash = temp;
				}
			}
		}
		if (!found)
		{
			cout << "NO" << endl;
		}
	}
}