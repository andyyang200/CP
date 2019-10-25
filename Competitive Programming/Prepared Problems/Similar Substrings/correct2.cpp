#include <bits/stdc++.h>
using namespace std;
#define PII pair <int, int>
#define LD long double
#define LL long long
#define MP make_pair
#define PB push_back
#define s second
#define f first
#define FOR(i, b, e) for (int i = b; i <= e; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, b, e) for (int i = b; i >= e; --i)
#ifdef DEB
#define debug(x...) fprintf(stderr, x);
#else
#define debug(...)
#endif
#define mini(a, b) a = min(a, b)
#define maxi(a, b) a = max(a, b)
#define siz(x) ((int)x.size())
const int MN = 4e3 + 10;
char a[MN], b[MN];
int n, m, k;
int ans = 0;
void Try(int p1, int p2) {
  debug("try %d %d\n", p1, p2);
  int head = 0, tail = 0, diff = 0;
  while (a[p1 + head] && b[p2 + head]) {
    if (a[p1 + head] != b[p2 + head]) diff++;
    head++;
    while (diff > k) {
      if (a[p1 + tail] != b[p2 + tail]) diff--;
      tail++;
    }
    debug("h = %d t = %d diff = %d\n", head, tail, diff);
    maxi(ans, head - tail);
  }
}
int main() {
    ans = 0;
    scanf("%d%s%s", &k, a, b);
    n = strlen(a);
    m = strlen(b);

    Try(0, 0);
    FOR(i, 1, m - 1)
      Try(0, i);
    FOR(i, 1, n - 1)
      Try(i, 0);
    printf("%d\n", ans);

}
