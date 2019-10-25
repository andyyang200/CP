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
    cout << 200000 << endl;
    srand(82828);
    FOR(i, 0, 200000){
        cout << 1 + i + rand() % 97 << " ";
    }
    cout << endl;
    FOR(i, 0, 200000){
        cout << 123123 + i + rand() % 97 << " ";
    }
    cout << endl;
}


