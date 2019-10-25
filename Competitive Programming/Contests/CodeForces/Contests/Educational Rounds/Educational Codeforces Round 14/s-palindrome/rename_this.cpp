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
map<char, char> key;
int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	key['A'] = 'A';
	key['b'] = 'd';
	key['d'] = 'b';
	key['H'] = 'H';
	key['I'] = 'I';
	key['M'] = 'M';
	key['O'] = 'O';
	key['o'] = 'o';
	key['p'] = 'q';
	key['q'] = 'p';
	key['T'] = 'T';
	key['U'] = 'U';
	key['V'] = 'V';
	key['v'] = 'v';
	key['W'] = 'W';
	key['w'] = 'w';
	key['X'] = 'X';
	key['x'] = 'x';
	key['Y'] = 'Y';
	string s;
	cin >> s;
	FOR(i, 0, s.length())
	{
		if (key[s[i]] != s[s.length() - 1 - i])
		{
			cout << "NIE" << endl;
			return 0;
		}
	}
	cout << "TAK" << endl;
}