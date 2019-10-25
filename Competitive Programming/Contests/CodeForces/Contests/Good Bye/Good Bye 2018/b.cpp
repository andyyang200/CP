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
int n;
int x[5000], y[5000], a[5000], b[5000];
bool check(int X, int Y){
    set<pii> s;
    FOR(i, 0, n){
        s.insert({a[i], b[i]});
    }
    FOR(i,0 , n){
        pii t = {X - x[i], Y - y[i]};
        auto itr = s.find(t);
        if (itr == s.end()){
            return false;
        }
        s.erase(itr);
    }
    return true;
}
int main(){
    cin >> n;
    FOR(i, 0, n){
        scanf("%d%d", x + i, y + i);
    }
    FOR(i, 0, n){
        scanf("%d%d", a + i, b + i);
    }
    FOR(i, 0, n){
        int X = x[0] + a[i];
        int Y = y[0] + b[i];
        if (check(X, Y)){
            cout << X << " " << Y << endl;
            return 0;
        }
    }

}

