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
int n, k;
int s[200005];
map<int, int> cnt;
bool check(int m){ // can you cut at least m times
    int ans = 0;
    FOREACH(itr, cnt){
        ans += itr->second / m;
    }
    return ans >= k;
}
int main(){
    cin >> n >> k;
    FOR(i, 0, n){
        scanf("%d", s + i);
        cnt[s[i]]++;
    }
    int ans = 0;
    int l = 1;
    int r = 200000;
    while(l <= r){
        int m = (l + r) >> 1;
        if (check(m)){
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    if (ans == 0){
        cout << s[0] << endl;
        return 0;
    }
    vector<int> res;
    FOREACH(itr ,cnt){
        FOR(i, 0, itr->second / ans){
            res.push_back(itr->first);
            if (res.size() == k){
                for(int x : res){
                    cout << x << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
}

