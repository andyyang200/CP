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

int n, m;
pii a[100];
pii b[100];
set<int> edgesa[100];
set<int> edgesb[100];
int match(pii x, pii y){
    if (x.first > x.second) swap(x.first, x.second);
    if (y.first > y.second) swap(y.first, y.second);
    if (x == y){
        return -1;
    }
    if (x.first == y.first || x.first == y.second){
        return x.first;
    } if (x.second == y.first || x.second == y.second){
        return x.second;
    }
    return -1;
}
int main(void)
{
    cin >> n >> m;
    FOR(i, 0, n){
        cin >> a[i].first >> a[i].second;
    }
    FOR(i, 0, m){
        cin >> b[i].first >> b[i].second;
    }
    FOR(i, 0, n){
        FOR(j, 0, m){
            int x = match(a[i], b[j]);
            if (x > 0){
                edgesa[i].insert(x);
                edgesb[j].insert(x);
            }
        }
    }

    set<int> sa;
    set<int> sb;
    FOR(i, 0, n){
        for(int x : edgesa[i]){
            sa.insert(x);
        }
    }
    FOR(i, 0, m){
        for(int x : edgesb[i]){
            sb.insert(x);
        }
    }
    if (sa.size() == 1){
        cout << *sa.begin() << endl;
        return 0;
    }
    if (sb.size() == 1){
        cout << *sb.begin() << endl;
        return 0;
    }
    FOR(i, 0, n){
        if (edgesa[i].size() > 1){
            cout << -1 << endl;
            return 0;
        }
    }
    FOR(i, 0, m){
        if (edgesb[i].size() > 1){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

}

