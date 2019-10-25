#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  int m = atoi(argv[2]);
  int k = n;
  vector< vector<int> > f(n, vector<int>(2, -1));
  vector< vector<int> > who(k);
  vector< pair<int,int> > edges;
  for (int i = 0; i < n; i++) {
    do {
      f[i][0] = rnd.next(k);
      f[i][1] = rnd.next(k);
    } while (f[i][0] == f[i][1]);
    vector<int> z = who[f[i][0]];
    z.insert(z.end(), who[f[i][1]].begin(), who[f[i][1]].end());
    sort(z.begin(), z.end());
    z.resize(unique(z.begin(), z.end()) - z.begin());
    if ((int) (edges.size() + z.size()) > m) {
      cerr << "broke at i = " << i << endl;
      break;
    }
    for (int j : z) {
      edges.emplace_back(i, j);
    }
    who[f[i][0]].push_back(i);
    who[f[i][1]].push_back(i);
  }
  m = (int) edges.size();
  vector<int> order(n);
  for (int i = 0; i < n; i++) {
    order[i] = i;
  }
  shuffle(order.begin(), order.end());
  for (int i = 0; i < m; i++) {
    edges[i].first = order[edges[i].first];
    edges[i].second = order[edges[i].second];
    if (rnd.next(2) == 0) {
      swap(edges[i].first, edges[i].second);
    }
  }
  shuffle(edges.begin(), edges.end());
  printf("%d %d\n", n, m);
  for (int i = 0; i < m; i++) {
    printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
  }
  return 0;
}
