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
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;
#define M 1000000007
#define P 3
unordered_map<int, unordered_map<ll, vector<string> > > censored;

int main()
{
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);
	string s;
	cin >> s;
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		ll hash = 0;
		string t;
		cin >> t;
		FOR(j, 0, t.length())
		{
			hash *= P;
			hash += t[j];
			hash %= M;
		}
		censored[t.length()][hash].push_back(t);
	}
	string r = "";
	vector<ll> hashes;
	vector<ll> powers;
	FOR(i, 0, s.length())
	{
		hashes.push_back(((hashes.size() == 0 ? 0 : hashes.back()) * P + s[i]) % 1000000007);
		powers.push_back((powers.size() == 0 ? 1 : powers.back() * 3) % 1000000007);
		r += s[i];
		for (auto itr = censored.begin(); itr != censored.end(); itr++)
		{
			int length = itr -> first;
			if (r.length() < length)
			{
				continue;
			}
			ll hash = hashes.back() + M;
			if (r.length() > length)
			{
				hash -= (powers[length] * hashes[r.length() - 1 - length]) % M;
			}	
			hash %= M;
			
			if (itr->second.find(hash) != itr->second.end())
			{
				bool found = false;
				string end = r.substr(r.length() - length);
				for (const string& t : itr->second[hash])
				{
					if (t == end)
					{
						found = true;
						r.resize(r.length() - length);
						hashes.resize(hashes.size() - length);
						powers.resize(powers.size() - length);
						break;
					}
				}
				if (found)
				{
					break;
				}
			}
		}
	}
	cout << r << endl;
}