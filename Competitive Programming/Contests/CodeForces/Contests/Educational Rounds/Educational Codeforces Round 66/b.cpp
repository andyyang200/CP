
#include <bits/stdc++.h>
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
using namespace std;
typedef long long ll;

int main(){
    int l;
    scanf("%d", &l);
    ll ans = 0;
    vector<ll> s;
    vector<ll> a;
    for(int i = 0; i < l; i++){
        string str;
        cin >> str;
        if (str == "add"){
            if (s.size() == 0) ans++;
            else{
                a[a.size() - 1]++;
            }
        }
        else if (str == "for"){
            int n;
            scanf("%d", &n);
            s.push_back(n);
            a.push_back(0);
        }
        else{
            if (a.size() > 1){
                a[a.size() - 2] += (ll)s.back() * a.back();
            }
            else{
                ans += (ll)s.back() * a.back();
            }
            s.pop_back();
            a.pop_back();
        }
        if (a.size() > 0 && a.back() > (1LL << 32) - 1){
            cout << "OVERFLOW!!!" << endl;
            return 0;
        }
        if (ans > (1LL << 32) - 1){
            cout << "OVERFLOW!!!" << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
