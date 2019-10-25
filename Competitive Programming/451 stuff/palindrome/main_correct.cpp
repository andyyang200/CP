#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int b = 37;
const int p = 1000000007;
ll ph[2000005];
ll powers[2000005];
string s;
int n;
void buildHash(){
    string t = s;
    reverse(t.begin(), t.end());
    s += t;
    powers[0] = 1;
    ph[0] = s[0];
    for(int i = 1; i < 2 * n; i++){
        powers[i] = b * powers[i - 1] % p;
        ph[i] = (ph[i - 1] * b + s[i]) % p;
    }
}
ll getHash(int l, int r){
    ll ans = ph[r];
    if (l > 0)
        ans -= ph[l - 1] * powers[r - l + 1] % p;
    return (ans + p) % p;
}
ll getHashReverse(int l, int r){
    return getHash(2 * n - 1 - r, 2 * n - 1 - l);
}
int extend(int l, int r){
    int low = 1;
    int high = min(l + 1, n - r);
    int ans = 0;
    while(low <= high){
        int m = (low + high) >> 1;
        if (getHash(r, r + m - 1) != getHashReverse(l - m + 1, l))
            high = m - 1;
        else{
            low = m + 1;
            ans = m;
        }
    }
    return ans;
}
pair<int, int> ans;
void atcenter(int i, int j){
    int d1 = extend(i, j);
    int l = i - (d1 - 1);
    int r = j + (d1 - 1);
    if (l != 0 && r != n - 1){
        int d2 = extend(l - 2, r + 2);
        l -= d2 + 1;
        r += d2 + 1;
    }
    if (r - l + 1 > ans.first || r - l + 1 == ans.first && l < ans.second)
        ans = {r - l + 1, l};
}
string getPalindrome(){
    ans = {0, n};
    for(int i = 0; i < n; i++){
        atcenter(i, i);
        if (i < n - 1)
            atcenter(i, i + 1);
    }
    return s.substr(ans.second, ans.first);
}
int main() {
    cin >> s;
    n = s.length();
    buildHash();
    cout << getPalindrome() << endl;
}
