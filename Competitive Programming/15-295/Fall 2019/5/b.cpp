#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define ri2(x, y) scanf("%d%d", &x, &y)
#define ri3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

bool check(string s){
    if (s.length() < 6) return false;
    int lower = 0;
    int upper = 0;
    int digit = 0;
    int p = 0;
    FOR(i, 0, s.length()){
        if (s[i] >= 'a' && s[i] <= 'z') lower++;
        else if (s[i] >= 'A' && s[i] <= 'Z') upper++;
        else if (s[i] >= '0' && s[i] <= '9') digit++;
        if (s[i] == '.')p++;
        if (s[i] == ',')p++;
        if (s[i] == ':')p++;
        if (s[i] == ';')p++;
        if (s[i] == '?')p++;
        if (s[i] == '!')p++;
    }
    if (lower == 0 || upper == 0) return false;
    if (digit == 0) return false;
    if (p == 0) return false;
    return true;
}

vector<string> ans;
int main(){
    int n;
    ri(n);
    FOR(i, 0, n){
        string s;
        cin >> s;
        if (check(s))ans.push_back(s);
    }
    cout << ans.size() << endl;
    for(string x : ans) cout << x << endl;
}

