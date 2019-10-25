#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
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
#include <bitset>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef long long ll;

int countSetBits(ll n)
{
	unsigned int count = 0;
	while (n)
	{
		n &= (n - 1);
		count++;
	}
	return count;
}

int main()
{
	freopen("xlite.in", "r", stdin);
	freopen("xlite.out", "w", stdout);

	int L, T;
	scanf("%d %d", &L, &T);
	char b[100];
	char f[10];
	scanf("%s %s", b, f);
	ll num = 0;
	ll fork = 0;
	int i;
	REP(i, L)
	{
		num = (num << 1) + b[i] - '0';
	}
	REP(i, T)
	{
		fork = (fork << 1) + f[i] - '0';
	}
	int numOri = num;
	int maxShift = L - T;
	vector<int> optimal;
	vector<int> current;
	int gMin = 1 << 30;
	for (int fs = maxShift; fs >= 0; fs--)
	{
		current.clear();
		ll f2 = fork << fs;
		current.push_back(maxShift - fs + 1);
		num = (numOri & f2) ^ (numOri | f2);
		//std::cout << std::bitset< 64 >(num) << endl; // direct output
		int weight = countSetBits(num);

		for (i = maxShift; i >= 0; i--)
		{
			ll f2 = fork << i;
			ll n2 = (num & f2) ^ (num | f2);
			int w2 = countSetBits(n2);
			if (w2 < weight)
			{
				//std::cout << std::bitset< 64 >(n2) << endl; // direct output
				num = n2;
				weight = w2;
				current.push_back(maxShift - i + 1);
				i = maxShift + 1;
			}
		}
		if (weight < gMin)
		{
			gMin = weight;
			optimal = current;
		}
	}
	cout << optimal.size() << endl;
	return 0;
}