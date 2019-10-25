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

const int N = 3e5;
vector<int> nm[N], fn[N];
int a[N], b[N];
int n, cnt, t;
pair<int, int> d[N];
int get(int x, int y) {
    int mx = 0;
    x--; y--;
    for (; x >= 1; x = (x & (x - 1))) {
        int l = upper_bound(nm[x].begin(), nm[x].end(), y) - nm[x].begin();
        for (int j = l - 1; j >= 1; j = (j & (j - 1))) mx = max(mx, fn[x][j]);
    }
    return mx;
}
void md(int x, int y, int k) {
    for (; x <= cnt; x = (x | (x - 1)) + 1) {
        int l = lower_bound(nm[x].begin(), nm[x].end(), y) - nm[x].begin();
        for (int j = l; j < nm[x].size(); j = (j | (j - 1)) + 1) fn[x][j] = max(fn[x][j], k);
    }
}
void add(int x, int y) {
    for (int i = x; i >= 1; i = (i & (i - 1))) nm[i].push_back(y);
    for (int i = x; i <= cnt; i = (i | (i - 1)) + 1) nm[i].push_back(y);

}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) d[i] = make_pair(a[i], i);
    sort(d + 1, d + n + 1);
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || d[i].first != d[i - 1].first) cnt++;
        a[d[i].second] = cnt;
    }
    for (int i = 1; i <= cnt; i++) {
        nm[i].clear();
        nm[i].push_back(0);
    }
    for (int i = 1; i <= n; i++) add(a[i], b[i]);
    for (int i = 1; i <= cnt; i++) {
        sort(nm[i].begin(), nm[i].end());
        int ccnt = 1;
        for (int j = 1; j < nm[i].size(); j++)
        if (nm[i][j] != nm[i][j - 1]) {
            ccnt++;
            nm[i][ccnt - 1] = nm[i][j];
        }
        nm[i].resize(ccnt);
        fn[i].resize(ccnt);
        for (int j = 0; j < ccnt; j++) fn[i][j] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int mx = get(a[i], b[i]);
        md(a[i], b[i], mx + 1);
        ans = max(ans, mx + 1);
    }
    printf("%d\n", ans);
}
