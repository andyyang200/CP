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



vector<string> original;
vector<string> previous;
vector<string> current;

int main()
{
	int q;
	cin >> q;
	FOR(i, 0, q)
	{
		string a, b;
		cin >> a >> b;
		int f = find(current.begin(), current.end(), a) - current.begin();
		if (f >= previous.size())
		{
			original.push_back(a);
			previous.push_back(a);
			current.push_back(b);
		}
		else
		{
			previous[f] = a;
			current[f] = b;
		}
	}
	cout << original.size() << endl;
	FOR(i, 0, original.size())
	{
		cout << original[i] << " " << current[i] << endl;
	}
}