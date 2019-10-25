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

int arr[101];

int main()
{
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> arr[i];
	}
	int count = 0;
	FOR(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		int bound = min(arr[a], arr[b]);
		FOR(j, 2, bound + 1)
		{
			while (arr[a] % j == 0 && arr[b] % j == 0)
			{
				arr[a] /= j;
				arr[b] /= j;
				bound /= j;
				count++;
			}
		}
	}
	cout << count << endl;
}