#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
int n, h;
int a[100005];

int main(){
    scanf("%d%d", &n, &h);
    FOR(i, 0, n){
        scanf("%d", &a[i]);
    }
    multiset<int> s;
    FOR(i, 0, n){
        s.insert(-a[i]);
        int used = 0;
        int prev = -1;
        for (int x : s){
            if (prev == -1){
                prev = -x;
            }
            else{
                used += prev;
                prev = -1;
            }

        }
        if (prev != -1){
            used += prev;
        }
        if (used > h){
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;


}

