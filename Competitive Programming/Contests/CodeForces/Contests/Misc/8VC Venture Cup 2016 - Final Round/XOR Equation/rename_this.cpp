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
	string Xor;
	string And;
	int main()
	{
		ll s, x;
		cin >> s >> x;
		if (s - x < 0)
		{
			cout << 0 << endl;
			return 0;
		}
		if ((s - x) % 2 != 0)
		{
			cout << 0 << endl;
			return 0;
		}
		bool subtract = false;
		if (s == x)
		{
			subtract = true;
		}
		ll ans = 1;
		ll a = (s - x) / 2;
		And = "";
		Xor = "";
		while (a > 0)
		{
			if (a % 2 == 1)
			{
				And = "1" + And;
			}
			else
			{
				And = "0" + And;
			}
			a /= 2;
		}
		while (x > 0)
		{
			if (x % 2 == 1)
			{
				Xor = "1" + Xor;
			}
			else
			{
				Xor = "0" + Xor;
			}
			x /= 2;
		}
		while (Xor.length() < And.length())
		{
			Xor = "0" + Xor;
		}
		while (And.length() < Xor.length())
		{
			And = "0" + And;
		}
		FOR(i, 0, Xor.length())
		{
			if (Xor[i] == '1')
			{
				if (And[i] != '0')
				{
					cout << 0 << endl;
					return 0;
				}
				ans *= 2;
			}
		}
		if (subtract)
		{
			ans -= 2;
		}
		cout << ans << endl;
	}