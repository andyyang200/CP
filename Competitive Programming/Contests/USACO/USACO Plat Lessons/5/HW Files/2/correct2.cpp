#include <bits/stdc++.h>
#define ff first
#define ss second
#define puba push_back
#define szof(x) ((int) (x).size())
#define bend(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

long long d[20][20], mn[(1 << 15)][15], sz[(1 << 15)];
long long dp[(1 << 15)], dp1[(1 << 15)][15];
vector<int> v[(1 << 15)];
int bit[(int) 1e5];

int main() {
	cout << fixed << setprecision(15);
	cerr << fixed << setprecision(15);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	//n = 15;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			cin >> d[i][j];
			//d[i][j] = 1;
			d[j][i] = d[i][j];
		}
	}
	for (int i = 0; i < 15; ++i) {
	 	bit[1 << i] = i;
	}
	for (int mask = 1; mask < (1 << n); mask++)
	{
		sz[mask] = 0;
		for (int i = 0; i < n; i++)
		{
			if ((mask & (1 << i)) == 0)
			{
				/*
				mn[mask][i] = (int)1e9 + 10;
				for (int j = 0; j < n; j++)
				{
					if (mask & (1 << j))
						mn[mask][i] = min(mn[mask][i], d[i][j]);
				}
				//*/
			}
			else
			{
				sz[mask]++;
				v[mask].push_back(i);
			}
		}
	}
	for (int i = 0; i < (1 << n); i++)
	{
		fill(dp1[i], dp1[i] + n, (long long)1e18 + 10);
	}
	for (int i = 0; i < n; i++)
	{
		dp1[(1 << i)][i] = 0;
		//dp[(1 << i)] = 0;
	}
	for (int mask = 3; mask < (1 << n); mask++)
	{
		if (__builtin_popcount(mask) == 1) {
		 	continue;
		}
		int tmpmask = mask;
  		while (tmpmask)
  		//int i = v[mask ^ mask2].front();
  		{
  			int i = bit[tmpmask & (-tmpmask)];
			tmpmask ^= tmpmask & (-tmpmask);

			int mask0 = mask ^ (1 << i);
			int tmp = mask0 & (-mask0);
			mask0 ^= tmp;
    		int mask2 = mask0;
    		while (true)
    		{
    			mask2 ^= tmp;
				long long cnt = (n - sz[mask2]) * sz[mask2];
				//int mask3 = (mask ^ mask2);

				int tmpmask2 = mask2;
				while (tmpmask2)
				//int j = v[mask2].front();
				{
					int j = bit[tmpmask2 & (-tmpmask2)];
					tmpmask2 ^= tmpmask2 & (-tmpmask2);
					//int tmp = dp1[mask ^ mask2][i] + dp1[mask2][j] + d[i][j] * cnt;
					//tmp < dp1[mask][i] ? dp1[mask][i] = tmp : 0;
					dp1[mask][i] = min(dp1[mask][i], dp1[mask ^ mask2][i] + dp1[mask2][j] + d[i][j] * cnt);
				}
				mask2 ^= tmp;
				if (mask2 == 0) {
				 	break;
				}
				mask2 = (mask0 & (mask2 - 1));
			}

		}
	}
	long long ans = dp1[(1 << n) - 1][0];
	for (int i = 1; i < n; i++)
		ans = min(ans, dp1[(1 << n) - 1][i]);
	cout << ans << endl;


	#ifdef LOCAL
		cerr << "time: " << clock() << endl;
	#endif
	return 0;
}
