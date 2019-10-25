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

char a[15];
vector<int> digits;

int main()
{
	int n;
	cin >> n;
	cin >> a;
	string result = "";
	FOR(i, 0, n)
	{
		switch (a[i])
		{
			case '0':
			{
				break;
			}
			case '1':
			{
				break;
			}
			case '4':
			{
				result += "322";
				break;
			}
			case '6':
			{
				result += "53";
				break;
			}
			case '8':
			{
				result += "7222";
				break;
			}
			case '9':
			{
				result += "7332";
				break;
			}
			default:
			{
				result += a[i];
				break;
			}
		}
	}
	sort(result.begin(), result.end());
	reverse(result.begin(), result.end());
	cout << result << endl;
}