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

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int misha = max(3 * a / 10, a - a / 250 * c);
	int vasya = max(3 * b / 10, b - b / 250 * d);
	if (misha > vasya)
	{
		cout << "Misha";
	}
	else if (misha < vasya)
	{
		cout << "Vasya";
	}
	else
	{
		cout << "Tie";
	}
	cout << endl;
}