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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrand(int n) { // [0, n)
    return uniform_int_distribution<int>(0, n - 1)(rng);
}
int getrand(int a, int b){ // [a, b]
    return uniform_int_distribution<int>(a, b)(rng);
}

int sizes[] = {10, 500, 20000, 50000, 100000, 130000, 150000, 199998, 199999, 200000};
int maxw[] = {20, 30000, 50000, 1000000000, 300, 1, 1000000000, 1000000000, 2, 1000000000};

int main() {
    FOR(test, 1, 11){
        string input = to_string(test) + ".in";
        freopen(input.c_str(), "w", stdout);

        int n = sizes[test - 1];
        cout << n << endl;

        vector<int> p;
        FOR(i, 1, n + 1){
            p.push_back(i);
        }
        shuffle(p.begin(), p.end(), rng);

        for(int i = 1; i < n; i++) {
            int x = getrand(0, i - 1);
            cout << p[x] << " " << p[i] << " " << getrand(1, maxw[test - 1]) << endl;
        }
        int a = getrand(1, n - 1);
        int b = getrand(1, n - a);
        shuffle(p.begin(), p.end(), rng);
        cout << a;
        FOR(i, 0, a) {
            cout << " ";
            cout << p[i];
        }
        cout << endl;
        cout << b;
        FOR(i, a, a + b) {
            cout << " ";
            cout << p[i];
        }
        cout << endl;
    }
}
