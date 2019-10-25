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

struct instrument
{
	int days, i;
	bool operator<(const instrument& a) const
	{
		return days < a.days;
	}
};
instrument instruments[100];

int main()
{
	int n, k;
	cin >> n >> k;
	FOR(i, 0, n)
	{
		cin >> instruments[i].days;
		instruments[i].i = i + 1;
	}
	sort(instruments, instruments + n);
	int count = 0;
	vector<int> indices;
	FOR(i, 0, n)
	{
		if (instruments[i].days <= k)
		{
			count++;
			indices.push_back(instruments[i].i);
			k -= instruments[i].days;
		}
		else
		{
			break;
		}
	}
	cout << count << endl;
	for (int i : indices)
	{
		cout << i << " ";
	}
	cout << endl;
}