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

void print(int n)
{
	if (n == 0)
	{
		cout << "zero" << endl;
	}
	if (n == 1)
	{
		cout << "one" << endl;
	}
	if (n == 2)
	{
		cout << "two" << endl;
	}
	if (n == 3)
	{
		cout << "three" << endl;
	}
	if (n == 4)
	{
		cout << "four" << endl;
	}
	if (n == 5)
	{
		cout << "five" << endl;
	}
	if (n == 6)
	{
		cout << "six" << endl;
	}
	if (n == 7)
	{
		cout << "seven" << endl;
	}
	if (n == 8)
	{
		cout << "eight" << endl;
	}
	if (n == 9)
	{
		cout << "nine" << endl;
	}
	if (n == 10)
	{
		cout << "ten" << endl;
	}
	if (n == 11)
	{
		cout << "eleven" << endl;
	}
	if (n == 12)
	{
		cout << "twelve" << endl;
	}
	if (n == 13)
	{
		cout << "thirteen" << endl;
	}
	if (n == 14)
	{
		cout << "fourteen" << endl;
	}
	if (n == 15)
	{
		cout << "fifteen" << endl;
	}
	if (n == 16)
	{
		cout << "sixteen" << endl;
	}
	if (n == 17)
	{
		cout << "seventeen" << endl;
	}
	if (n == 18)
	{
		cout << "eighteen" << endl;
	}
	if (n == 19)
	{
		cout << "nineteen" << endl;
	}
	if (n >= 20 && n < 30)
	{
		cout << "twenty";
		if (n % 10 != 0)
		{
			cout << "-";
			print(n % 10);
		}
	}
	if (n >= 30 && n < 40)
	{
		cout << "thirty";
		if (n % 10 != 0)
		{
			cout << "-";
			print(n % 10);
		}
	}
	if (n >= 40 && n < 50)
	{
		cout << "forty";
		if (n % 10 != 0)
		{
			cout << "-";
			print(n % 10);
		}
	}
	if (n >= 50 && n < 60)
	{
		cout << "fifty";
		if (n % 10 != 0)
		{
			cout << "-";
			print(n % 10);
		}
	}
	if (n >= 60 && n < 70)
	{
		cout << "sixty";
		if (n % 10 != 0)
		{
			cout << "-";
			print(n % 10);
		}
	}
	if (n >= 70 && n < 80)
	{
		cout << "seventy";
		if (n % 10 != 0)
		{
			cout << "-";
			print(n % 10);
		}
	}
	if (n >= 80 && n < 90)
	{
		cout << "eighty";
		if (n % 10 != 0)
		{
			cout << "-";
			print(n % 10);
		}
	}
	if (n >= 90 && n < 100)
	{
		cout << "ninety";
		if (n % 10 != 0)
		{
			cout << "-";
			print(n % 10);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	print(n);
}