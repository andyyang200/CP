#include <bits/stdc++.h>
#include "testlib.h"

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
    int maxv = atoi(argv[2]);
    int i = 0;
    cout << n << endl;
    while(i < n){
        int x1 = rnd.next(-maxv, maxv);
        int y1 = rnd.next(-maxv, maxv);
        int x2 = rnd.next(-maxv, maxv);
        int y2 = rnd.next(-maxv, maxv);
        if (x1 == x2 || y1 == y2){
            continue;
        }
        printf("%d %d %d %d\n", x1, y1, x2, y2);
        i++;
    }
}
