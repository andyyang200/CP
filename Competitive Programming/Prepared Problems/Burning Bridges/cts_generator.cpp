#include "testlib.h"
#include <iostream>

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

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    vector<int> p = rnd.perm(n, 1);
    cout << n << endl;
    for(int i = 1; i < n; i++) {
        int x = rnd.next(0, i - 1);
        cout << p[x] << " " << p[i] << " " << rnd.next(1, 1000000000) << endl;
    }
    int a = rnd.next(1, n - 1);
    int b = rnd.next(1, n - a);
    p = rnd.perm(n, 1);
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
