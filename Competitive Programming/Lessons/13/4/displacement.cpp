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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

/*.
You are given an array of N numbers numbered from 0 through N - 1. The array is a permutation of the first N nonegative integers.
Let the displacement of a permutation be the sum of abs(Ai - i) for all i.
If you are allowed to perform cyclical shifts on the permutation, what is the minimum possible displacement?
N <= 10^6
*/

















int p[1000005];
int v[1000005];
int main(void)
{
	int n;
	scanf("%d", &n);
	ll deviation = 0;
	int a = 0;
	int b = 0;
	FOR(i, 1, n + 1) {
		scanf("%d", &p[i]);
		deviation += (ll)abs(p[i] - i);
		if (p[i] > i) {
			v[p[i] - i]++;
			a++;
		}
		else {
			b++;
			if (p[i] > 1) {
				v[p[i] - i + n]++;
			}
		}
	}
	int end = n;
	ll minDeviation = deviation;
	FOR(i, 0, n - 1) {
		deviation -= a;
		deviation += b - 1;
		deviation -= (n - p[end]);
		deviation += p[end] - 1;
		if (p[end] > 1) {
			b--;
			a++;
			/*if (i + p[end] - 1 <= n) {
				v[i + p[end] - 1]++;
			}*/
		}
		a -= v[i];
		b += v[i];
		end--;
		minDeviation = min(minDeviation, deviation);
	}
	cout << minDeviation << endl;
}