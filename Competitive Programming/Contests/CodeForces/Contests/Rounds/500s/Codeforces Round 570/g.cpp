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

struct p{
    int a, b;
    bool operator<(p o) const{
        if (a != o.a){
            return a < o.a;
        }
        return b > o.b;
    }
};
p a[200005];
int main(){
    int q;
    scanf("%d", &q);
    FOR(i, 0, q){
        int n;
        scanf("%d", &n);
        FOR(i, 0, n + 1){
            a[i] = {0, 0};
        }
        multiset<p> s;
        FOR(i, 0, n){
            int x, y;
            scanf("%d%d", &x, &y);
            a[x].a++;
            a[x].b += y;
        }
        FOR(i, 0, n + 1){
            if (a[i].a != 0)
                s.insert(a[i]);
        }
        ll ans1 = 0;
        ll ans2 = 0;
        RFOR(cnt, n, 0){
            auto itr = s.lower_bound({cnt, INF});
            if (itr != s.end()){
                int take = min(cnt, itr->a);
                ans1 += take;
                ans2 += min(take, itr->b);
                s.erase(itr);
            }
        }
        printf("%lld %lld\n", ans1, ans2);
    }
}

