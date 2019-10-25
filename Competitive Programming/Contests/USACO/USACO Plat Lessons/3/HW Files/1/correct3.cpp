#define M_E        2.71828182845904523536   // e
#define M_LOG2E    1.44269504088896340736   // log2(e)
#define M_LOG10E   0.434294481903251827651  // log10(e)
#define M_LN2      0.693147180559945309417  // ln(2)
#define M_LN10     2.30258509299404568402   // ln(10)
#define M_PI       3.14159265358979323846   // pi
#define M_PI_2     1.57079632679489661923   // pi/2
#define M_PI_4     0.785398163397448309616  // pi/4
#define M_1_PI     0.318309886183790671538  // 1/pi
#define M_2_PI     0.636619772367581343076  // 2/pi
#define M_2_SQRTPI 1.12837916709551257390   // 2/sqrt(pi)
#define M_SQRT2    1.41421356237309504880   // sqrt(2)
#define M_SQRT1_2  0.707106781186547524401  // 1/sqrt(2)
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define IN_FILE "in.txt"
#define OUT_FILE "out.txt"

#define EPS 1e-6
#define INF 1e18
#define SMALL_INF 1e8

#pragma warning (disable : 4996)

vector<int> v;

vector<map<int, long long>> vm;

vector<pair<long long, long long>> dp;

const long long MOD = 1000000007;

void add(long long &a, long long b)
{
	a = (a + b) % MOD;
}
int n, h;
long long tupoe()
{
	vm.clear();
	vm.resize(n);
	vm[0][h] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		for (auto val : vm[i])
		{
			int x = v[i], y = val.first;
			if (x == y)
			{
				if (i + x < n)
					add(vm[i + x][x], val.second);
			}
			else
			{
				if (i + x < n)
					add(vm[i + x][x], val.second);
				if (i + y < n)
					add(vm[i + y][y], val.second);
			}
		}
		vm[i].clear();
	}
	long long ans = 0;
	for (auto val : vm[n - 1])
		add(ans, val.second);
	return  ans;
}

long long solve()
{
	dp.assign(n, {0,0});
	dp[0].first = 1;
	if (h != v[0]) {
		for (int i = h; i < n; i += h)
		{
			if (v[i] == h)
			{
				dp[i].second += 1;
			}
			else
			{
				dp[i].first += 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		int step = v[i];
		for (int j = i + step; j < n; j += step)
		{
			if (v[j] == step)
			{
				add(dp[j].second, dp[i].first);
			}
			else
			{
				add(dp[j].first, dp[i].first);
			}
		}
	}
	long long ans = dp[n - 1].first;
	add(ans, dp[n - 1].second);
	//cout << ans << endl;
	return ans;
}

int main()
{
#ifdef  _DEBUG
	freopen(IN_FILE, "r", stdin);
	freopen(OUT_FILE, "w", stdout);
#endif
	srand(time(0));
	string s;
	cin >> s;
	if (s == "T") {
		int T = 100;
		while (T--)
		{
			n = rand() % 20 + 5;
			h = rand() % n + 1;
			v.resize(n);
			//cout << n << " " << h << endl;
			for (int i = 0; i < n; i++)
				v[i] = rand() % n + 1;
			//cout << endl;
			long long rr = solve(), rrr = tupoe();
			if (rr!= rrr) {
				cout << "ERROR\n";
				cout << n << " " << h << endl;
				for (int i : v)
					cout << i << " ";
				cout << endl;
			}
		}
	}
	else {
		n = atoi(s.c_str());
		cin >> h;
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &v[i]);
		}
		cout << solve() << endl;
#ifdef _DEBUG
		cout << tupoe() << endl;
#endif
	}
	return 0;
}

