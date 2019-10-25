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

int main(void)
{
    freopen("test.out", "w", stdout);
    cout << 50000 << endl;
    srand(1029481);
    FOR(i, 0, 12500){
        printf("1 %d %d %d\n", rand() * 2357, rand() * 2375, rand() * 7732);
    }
    FOR(i, 0, 12500){
        printf("1 %d %d %d\n", -rand() * 2753, rand() * 7352, rand() * 9812);
    }
    FOR(i, 0, 25000){
        printf("2 %d %d %d %d\n", -1000000000 + i, 1000000000 - i, -1000000000 + i, 1000000000 - i);
    }
}


