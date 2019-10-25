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
#define M 998244353
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string a[100005];
ll sum[25];
int l[15];
int main(){
    int n;
    cin >> n;
    int maxlenght  = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        l[a[i].length()]++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i].length(); j++){
            int d = a[i][a[i].length() - j - 1] - '0';
            int p = a[i].length();
            for(int q = 1; q <= 10; q++){
                if (j + 1 <= q){
                    sum[2 * j + 1] += l[q] * d % M;
                    sum[2 * j + 1] %= M;
                }
                else{
                    sum[j + q] += l[q] * d % M;
                    sum[j + q] %= M;
                }
            }
            int q = a[i].length();
            for(int p = 1; p <= 10; p++){
                if (p < j + 1){
                    sum[j + p] += l[p] * d % M;
                    sum[j + p] %= M;
                }
                else{
                    sum[2 * j] += l[p] * d % M;
                    sum[2 * j] %= M;
                }
            }

        }
    }
    ll ans = 0;
    ll pow = 1;
    for(int i = 0; i < 25; i++){
        ans += pow * sum[i] % M;
        ans %= M;
        pow *= 10;
        pow %= M;
    }
    cout << ans << endl;

}

