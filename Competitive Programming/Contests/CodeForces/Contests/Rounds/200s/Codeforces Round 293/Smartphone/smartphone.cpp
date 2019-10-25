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
#include <unordered_map>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;

unordered_map<int, int> position;
int menu[100000];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, n)
	{
		int a;
		scanf("%d", &a);
		menu[i] = a;
		position[a] = i;
	}
	ll gestures = 0;
	FOR(i, 0, m)
	{
		int a;
		scanf("%d", &a);
		gestures += position[a] / k + 1;
		if (position[a] != 0)
		{
			swap(menu[position[a]], menu[position[a] - 1]);
			position[menu[position[a]]]++;
			position[a]--;
		}
	}
	cout << gestures << endl;
}