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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int z[100001]; // z[i] = length of substring of s that starts at i that matches the beginning of s
string s;
void Z() {

	int n = s.length();
	int L = 0, R = 0;
	for (int i = 1; i < n; i++){
		if (i > R){
			L = R = i;
			while (R < n && s[R - L] == s[R])
				R++;
			z[i] = R - L;
			R--;
		}
		else{
			int k = i - L;
			if (z[k] < R - i + 1)
				z[i] = z[k];
			else{
				L = i;
				while (R < n && s[R - L] == s[R])
					R++;
				z[i] = R - L; R--;
			}
		}
	}
}
int main2(void)
{
	return 0;
}