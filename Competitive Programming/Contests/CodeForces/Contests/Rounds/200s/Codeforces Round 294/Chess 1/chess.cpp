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

int main()
{
	int b = 0, w = 0;
	FOR(i, 0, 8)
	{
		FOR(i, 0, 8)
		{
			char c;
			cin >> c;
			if (c == 'Q')
			{
				w += 9;
			}	
			if (c == 'R')
			{
				w += 5;
			}
			if (c == 'B')
			{
				w += 3;
			}
			if (c == 'N')
			{
				w += 3;
			}
			if (c == 'P')
			{
				w += 1;
			}
			if (c == 'q')
			{
				b += 9;
			}
			if (c == 'r')
			{
				b += 5;
			}
			if (c == 'b')
			{
				b += 3;
			}
			if (c == 'n')
			{
				b += 3;
			}
			if (c == 'p')
			{
				b += 1;
			}
		}
	}
	if (w > b)
	{
		cout << "White";
	}
	else if (b > w)
	{
		cout << "Black";
	}
	else
	{
		cout << "Draw";
	}
	cout << endl;
}