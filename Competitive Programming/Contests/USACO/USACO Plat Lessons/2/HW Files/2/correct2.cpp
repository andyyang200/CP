#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

unsigned int sz = 1;
vector<set<pair<unsigned int, unsigned int>>> dp;

int main(void)
{
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    unsigned int n;
    cin >> n;

    vector<unsigned int>a(n), b(n);
    vector<int> all{ 0 };
    for (unsigned int i = 0; i < n; i++) {
        cin >> a[i];
        all.push_back(a[i]);
    }
    sort(all.begin(), all.end());
    all = { all.begin(), unique(all.begin(), all.end()) };
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
    }
    for (unsigned int i = 0; i < n; i++)
        cin >> b[i];

    dp.clear();
    sz = 1;
    while (sz <= n)
        sz <<= 1;
    dp.resize(n + 1);
    dp[0].insert({ 0, 0 });
    unsigned int ans = 0;

    for (unsigned int i = 0; i < n; i++) {
        unsigned int l = 0, r = n;
        while (l != r - 1) {
            unsigned int m = (l + r) >> 1;
            auto j = dp[m].lower_bound({ a[i], 0 });
            if (j == dp[m].begin()) {
                r = m;
                continue;
            }
            j--;
            if (j->second < b[i]) {
                l = m;
            }
            else {
                r = m;
            }
        }
        l++;
        ans = max(ans, (unsigned int)l);
        dp[l].insert({ a[i], b[i] });
        auto j = dp[l].lower_bound({ a[i], b[i] });
        if (j != dp[l].begin()) {
            auto k = j;
            k--;
            if (k->second < j->second) {
                dp[l].erase(j);
                continue;
            }
        }
        auto k = j;
        k++;
        while (k != dp[l].end()) {
            if (k->second < j->second)
                break;
            else {
                dp[l].erase(k);
                k = j;
                k++;
            }
        }
    }

    cout << ans << '\n';
	return 0;
}


