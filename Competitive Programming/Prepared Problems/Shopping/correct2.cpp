/**
 *    author:  tourist
 *    created: 21.02.2018 19:03:21
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long) 2e18;

inline long long sqr(long long x) {
  return x * x;
}

void update(vector<long long> &f, vector<long long> &nf, vector<long long> &a, int from, int to) {
  if (from == to) {
    return;
  }
  int mid = (from + to) >> 1;
  update(f, nf, a, from, mid);
  update(f, nf, a, mid + 1, to);
  vector< pair<long long, long long> > lines;
  for (int i = from; i <= mid; i++) {
    long long k = -2 * a[i + 1];
    long long b = f[i] + a[i + 1] * a[i + 1];
    lines.emplace_back(k, b);
  }
  sort(lines.rbegin(), lines.rend());
  vector< pair<long long, long long> > st;
  vector<double> sx;
  for (int i = 0; i < (int) lines.size(); i++) {
    if (i + 1 < (int) lines.size() && lines[i + 1].first == lines[i].first) {
      continue;
    }
    auto &p = lines[i];
    while (st.size() >= 2) {
      double x = (double) (p.second - st.back().second) / (double) (st.back().first - p.first);
      if (x <= sx.back()) {
        st.pop_back();
        sx.pop_back();
      } else {
        break;
      }
    }
    if (!st.empty()) {
      double x = (double) (p.second - st.back().second) / (double) (st.back().first - p.first);
      sx.push_back(x);
    }
    st.push_back(p);
  }
  for (int i = mid + 1; i <= to; i++) {
    int low = 0, high = (int) st.size() - 1;
    while (low < high) {
      int midd = (low + high) >> 1;
      if ((double) a[i] > sx[midd]) {
        low = midd + 1;
      } else {
        high = midd;
      }
    }
    nf[i] = min(nf[i], a[i] * a[i] + st[low].first * a[i] + st[low].second);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> f(n);
  for (int i = 0; i < n; i++) {
    f[i] = sqr(a[0] - a[i]);
  }
  for (int j = 2; j <= k; j++) {
    vector<long long> nf(n, inf);
    update(f, nf, a, j - 2, n - 1);
    swap(f, nf);
  }
  cout << f[n - 1] << endl;
  return 0;
}
