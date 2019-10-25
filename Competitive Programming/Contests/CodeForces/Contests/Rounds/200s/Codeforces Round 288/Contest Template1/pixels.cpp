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

bool board[1005][1005];
bool check(int r, int c)
{
	if (board[r][c] && board[r + 1][c] && board[r][c + 1] && board[r + 1][c + 1])
	{
		return true;
	}
	return false;
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	FOR(i, 0, k)
	{
		int r, c;
		cin >> r >> c;
		board[r][c] = true;
		if (check(r, c) || check(r - 1, c) || check(r, c - 1) || check(r - 1, c - 1))
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}