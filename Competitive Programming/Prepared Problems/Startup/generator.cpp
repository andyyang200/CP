#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    ensure(argc >= 3);
    
    string mode = argv[1];
    int n = atoi(argv[2]);
    int k = atoi(argv[3]);
    int add = argc > 4 ? atoi(argv[4]) : 0;
    int del = argc > 5 ? atoi(argv[5]) : 0;
    
    vector<pii> e;
    
    for (int i = 0; i < k; ++i) {
        e.push_back(pii(0, i + 1));
    }
    for (int i = k + 1; i < n; ++i) {
        e.push_back(pii(rnd.next(1, k), i));
    }
    
    for (int i = 0; i < add; ++i) {
        int x = rnd.next(0, n - 1);
        int y = rnd.next(0, n - 1);
        if (x > y) swap(x, y);
        if (count(e.begin(), e.end(), pii(x, y)) or x == y) continue;
        e.push_back(pii(x, y));
    }
    
    for (int i = 0; i < del && e.size(); ++i) {
        int id = rnd.next(0, (int)e.size() - 1);
        e.erase(e.begin() + id);
    }
    
    // reorder
    vector<int> v(n); for (int i = 0; i < n; ++i) v[i] = i + 1;
    shuffle(v.begin(), v.end());
    shuffle(e.begin(), e.end());
    
    cout << n << ' ' << e.size() << endl;
    for (int i = 0; i < e.size(); ++i) {
        if (rnd.next(0, 1))
            cout << v[e[i].first] << ' ' << v[e[i].second] << endl;
        else
            cout << v[e[i].second] << ' ' << v[e[i].first] << endl;
    }
    
    return 0;
}
