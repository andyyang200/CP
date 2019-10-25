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
vector<string> prices;
int main(void)
{
	string s;
	cin >> s;
	FOR(i, 1, s.length())
	{
		if (s[i] >= '0' && s[i] <= '9' && s[i - 1] >= 'a' && s[i - 1] <= 'z')
		{
			string price = "";
			FOR(j, i, s.length())
			{
				if ((s[j] >= '0' && s[j] <= '9') || s[j] == '.')
				{
					price += s[j];
				}
				else
				{
					break;
				}
			}
			int dot = -1;
			RFOR(i, price.length() - 1, -1)
			{
				if (price[i] == '.')
				{
					dot = i;
					break;
				}
			}
			if ( dot != -1 && price.length() - dot == 3)
			{
				for(int k = dot - 1; k >= 0; k--)
				{
					if (price[k] == '.')
					{
						price.erase(price.begin() + k);
					}
				}
			}
			else
			{
				for (int k = price.length() - 1; k >= 0; k--)
				{
					if (price[k] == '.')
					{
						price.erase(price.begin() + k);
					}
				}
			}
			prices.push_back(price);
		}
	}
	double a = 0;
	FOR(i, 0, prices.size())
	{
		a += stod(prices[i]);
	}
	string ans = to_string(a);
	int dot = -1;
	RFOR(i, ans.length() - 1, -1)
	{
		if (ans[i] == '.')
		{
			dot = i;
			break;
		}
	}
	while (dot != -1 && ans[ans.length() - 1] == '0')
	{
		ans.erase(--ans.end());
	}
	if (ans[ans.length() - 1] == '.')
	{
		ans.erase(--ans.end());
		dot = -1;
	}
	while (dot != -1 && ans.length() - dot < 3)
	{
		ans += '0';
	}
	if (dot != -1 && ans.length() - dot == 3)
	{
		for (int k = dot - 3; k > 0; k -= 3)
		{
			ans.insert(k, ".");
		}
	}
	else
	{
		for (int k = ans.length() - 3; k > 0; k -= 3)
		{
			ans.insert(k, ".");
		}
	}
	cout << ans << endl;
}