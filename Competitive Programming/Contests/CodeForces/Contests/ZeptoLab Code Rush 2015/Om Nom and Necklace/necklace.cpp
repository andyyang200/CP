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
#define P 257
typedef long long ll;
typedef pair<int, int> pii;

ll hashes[1000000];
ll powers[1000000];
int good[1000000];
ll getHash(int l, int r)
{
	if (l > r)
	{
		return -1;
	}
	ll hash = hashes[r];
	if (l > 0)
	{
		hash = hash - hashes[l - 1] * powers[r - l + 1] % M;
		if (hash < 0)
		{
			hash += M;
		}
		hash %= M;
	}
	return hash;
}
int n, k;
bool check(int a, int b)
{
	ll hasha = getHash(0, a - 1);
	ll hashb = getHash(a, a + b - 1);
	int position = 0;
	FOR(i, 0, k + 1)
	{
		if (getHash(position, position + a - 1) != hasha)
		{
			return false;
		}
		position += a + b;
	}
	position = a;
	FOR(i, 0, k)
	{
		if (getHash(position, position + b - 1) != hashb)
		{
			return false;
		}
		position += a + b;
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &k);
	string beads;
	cin >> beads;
	hashes[0] = beads[0] - 'a';
	powers[0] = 1;
	FOR(i, 1, n)
	{
		hashes[i] = P * hashes[i - 1] + beads[i] - 'a';
		hashes[i] %= M;
		powers[i] = P * powers[i - 1];
		powers[i] %= M;
	}
	FOR(a, 0, n)
	{
		if (a * (k + 1) > n)
		{
			break;
		}
		FOR(b, 0, n)
		{
			if (a == 0 && b == 0)
			{
				continue;
			}
			int end = a * (k + 1) + b * k;
			if (end > n)
			{
				break;
			}
			if (check(a, b))
			{
				good[end - 1] = 1;
			}
		}
	}
	FOR(i, 0, n)
	{
		cout << good[i];
	}
	cout << endl;
}