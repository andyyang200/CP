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

vector<int> Z(string s) {
    int n = s.length();
	vector<int> z(n);
	int L = 0, R = 0;
	for (int i = 1; i < n; i++){
		if (i > R){
			L = R = i;
			while (R < n && s[R - L] == s[R])
				R++;
			z[i] = R - L;
			R--;
		}
		else{
			int k = i - L;
			if (z[k] < R - i + 1)
				z[i] = z[k];
			else{
				L = i;
				while (R < n && s[R - L] == s[R])
					R++;
				z[i] = R - L; R--;
			}
		}
	}
	return z;
}
int pref[300005];
int suff[300005];
string rev(string s){
    string ans = s;
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    string t;
    int q;
    cin >> t >> q;
    int n = t.length();
    int ans = 0;
    FOR(i, 0, q){
        string p;
        cin >> p;
        int m = p.length();
        vector<int> z2 = Z(t + '$' + p);
        vector<int> z1 = Z(rev(t) + '$' + rev(p));
        for(int j = 0; j < n; j++){
			if(j - n + 1 >= 0){
				if(pref[j - n + 1] + z1[m + n - j] >= n){
					ans++;
				}
			}
			pref[j] = max((j > 0 ? pref[j - 1] : 0), z2[n + j + 1]);
		}
    }
    cout << ans << endl;

}


