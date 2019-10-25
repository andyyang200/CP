
//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
typedef long long ll;
typedef pair<int, int> pii;

int p[200005];
int a[200005];
int get(int l, int r){
    int ans = p[r];
    if (l > 0) ans -= p[l - 1];
    return ans;
}
int zero(int l, int r){
    return get(l, r) < r - l + 1;
}
int loc[200005];
int main() {
    int n;
    cin >> n;
    FOR(i, 0, n){
        scanf("%d", &a[i]);
        a[i]--;
        loc[a[i]] = i;
    }
    string s;
    cin >> s;
    p[0] = s[0] - '0';
    FOR(i, 1, n - 1){
        p[i] = p[i - 1] + s[i] - '0';
    }
    FOR(i, 0, n){
        int a = i;
        int b = loc[i];
        if (a > b) swap(a, b);
        if (b > a && zero(a, b - 1)){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

}
