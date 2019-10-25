#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// @ a b a b b $
// 0121414123210
vector<int> manacher2(string s) {
	string t = "@#";
	for (int i = 0; i < s.length(); ++i) {
		t += s[i];
		t += "#";
	}
	t += "$";
	int n = t.length();
	vector<int> len(n);
	int l = 1, r = 1;
	for (int i = 1; i < n - 1; ++i) {
		len[i] = min(r - i, len[l + (r - i)]);
		while (t[i - len[i]] == t[i + len[i]]) ++len[i];
		if (i + len[i] > r) {
			l = i - len[i];
			r = i + len[i];
		}
	}
	return len;
}

vector<int> manacher(string s) {
    string s1 = "@";
    for (char c: s) s1 += c, s1 += "#";
    s1[s1.length()-1] = '&';

    vector<int> ans(s1.length()-1);
    int lo = 0, hi = 0;
    for(int i = 1; i < s1.length() - 1; i++) {
        if (i != 1) ans[i] = min(hi-i,ans[hi-i+lo]);
        while (s1[i-ans[i]-1] == s1[i+ans[i]+1]) ans[i] ++;
        if (i+ans[i] > hi) lo = i-ans[i], hi = i+ans[i];
    }

    ans.erase(ans.begin());
    for(int i = 0; i < ans.size(); i++)
        if ((i&1) == (ans[i]&1)) ans[i] ++; // adjust lengths
    vector<int> ret;
    return ans;
}

int main() {
	auto vec = manacher("‘Twas-brillig,-and-the-slithy-toves-did-gyre-and-gimble-in-the-wabe.");
	for (int x : vec) printf("%d", x);
	printf("\n");

    int maxlen = 0;
    int maxind = -1;
    for(int i = 0; i < vec.size(); i++){
        if (vec[i] > maxlen){
            maxlen = vec[i];
            maxind = i;
        }
    }
    int start = -1;
    if (maxind % 2 == 0){ // centered on a character
        start = maxind / 2 - (maxlen - 1) / 2;
    }
    else{ // centered between two characters
        start = maxind / 2 - maxlen / 2 + 1;
    }
    printf("start: %d, len: %d\n", start, maxlen);
}

