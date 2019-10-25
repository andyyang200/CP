#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair


const int N = (int) 1e5 + 100;
vector <int> g[N];
long long answer;


struct State
{
	vector <int> cnt;
	vector <long long> cntPairs;
	int upPairs;

	long long getPairs(int i)
	{
		i += upPairs;
		if (i >= (int) cntPairs.size() ) return 0;
		return cntPairs[i];
	}

	int getCnt(int i)
	{
		return cnt[(int) cnt.size() - i - 1];
	}

	void addPairs(int i, long long x)
	{
		i += upPairs;
		while (i >= (int) cntPairs.size() )
			cntPairs.push_back(0);
		cntPairs[i] += x;
	}

	void up()
	{
		answer += getPairs(0);
		cnt.push_back(1);
		upPairs += 1;
	}

	int h()
	{
		return (int) cnt.size();
	}

	void eprint()
	{
		for (int x : cnt)
			eprintf("%d ", x);
		eprintf("<< cnt\n");
		for (long long x : cntPairs)
			eprintf("%lld ", x);
		eprintf("<< cntPairs\n");
		eprintf("%d\n", upPairs);
		eprintf("-------------\n");
	}
};

State state[N];
int stsz;

int merge(int a, int b)
{
	if (state[a].h() < state[b].h() ) swap(a, b);

	for (int i = 0; i < state[b].h(); i++)
	{
		answer += state[b].getPairs(i + 1) * state[a].getCnt(i);
		answer += state[a].getPairs(i + 1) * state[b].getCnt(i);
	}

	for (int i = 0; i <= state[b].h(); i++)
	{
		if (i < state[b].h())
		{
			state[a].addPairs(i + 1, state[a].getCnt(i) * 1LL * state[b].getCnt(i) );
			state[a].cnt[(int) state[a].cnt.size() - i - 1] += state[b].getCnt(i);
		}
		state[a].addPairs(i, state[b].getPairs(i));
	}

	return a;
}

int dfs(int v, int par)
{
	int cur = stsz++;
	state[cur] = State();

	for (int to : g[v] )
	{
		if (to == par) continue;
		int nx = dfs(to, v);
		cur = merge(nx, cur);
	}
	state[cur].up();

//	eprintf("V = %d\n", v);
//	state[cur].eprint();

	return cur;
}

void solve()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0, 0);
	printf("%lld\n", answer);
}

int main()
{
    solve();
}
