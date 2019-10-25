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
int arr[5001];
int query[5001];
int main(void)
{
	int n;
	scanf("%d", &n);
	cout << "? " << 1 << " " << n << endl;;
	fflush(stdout);
	int a;
	cin >> a;
	cout << "? " << 2 << " " << n << endl;
	fflush(stdout);
	int b;
	cin >> b;
	FOR(i, 2, n)
	{
		cout << "? " << 1 << " " << i << endl;
		fflush(stdout);
		cin >> query[i];
		if (i == 2)
		{
			int difference = b - a;
			arr[2] = (difference + query[2]) / 2;
			arr[1] = arr[2] - difference;
		}
		else
		{
			arr[i] = arr[i - 1] + query[i] - query[i - 1];
		}
	}
	arr[n] = arr[n - 1] + a - query[n - 1];
	cout << "! ";
	FOR(i, 1, n + 1)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}