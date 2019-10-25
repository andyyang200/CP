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
typedef long long ll;
typedef pair<int, int> pii;

ll A[100001];
ll B[100001];

int main() 
{
	freopen("taxi.in", "r", stdin);
	freopen("taxi.out", "w", stdout);

	int N, M;
	cin >> N >> M;

	ll res = 0;
	for (int i = 0; i < N; i++) 
	{
		cin >> A[i] >> B[i];
		res += abs(A[i] - B[i]);
	}
	A[N] = M;
	B[N] = 0;
	N++;
	sort(A, A + N);
	sort(B, B + N);
	for (int i = 0; i < N; i++) 
	{
		res += abs(A[i] - B[i]);
	}
	cout << res << '\n';
}