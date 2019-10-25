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
int x[2005];
int y[2005];
ll getd(int x1, int y1, int x2, int y2){
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    return dx * dx + dy * dy;
}
int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    FOR(i, 0, n){
        scanf("%d%d", x + i, y + i);
    }
    FOR(i, 0, q){
        int a, b;
        scanf("%d%d", &a, &b);
        ll mind = getd(a, b, x[0], y[0]);
        FOR(i, 1, n){
            mind = min(mind, getd(a, b, x[i], y[i]));
        }
        vector<int> v;
        FOR(i, 0, n){
            if (getd(a, b, x[i], y[i]) == mind){
                v.push_back(i + 1);
                if (v.size() == 3) break;
            }
        }
        if (v.size() == 1){
            printf("REGION %d\n", v[0]);
        }
        else if (v.size() == 2){
            printf("LINE %d %d\n", v[0], v[1]);
        }
        else{
            printf("POINT\n");
        }
    }

}

