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
struct student{
    int i, l, r;
    bool operator<(const student o) const{
        if (l != o.l){
            return l < o.l;
        }
        return i < o.i;
    }
};
student s[10000];
int ans[100001];
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        FOR(i, 0, n){
            int l, r;
            scanf("%d%d", &l, &r);
            s[i].i = i;
            s[i].l = l;
            s[i].r = r;
        }
        sort(s, s + n);
        int t = 0;
        FOR(i, 0, n){
            if (t < s[i].l) t = s[i].l;
            if (t > s[i].r){
                ans[i] = 0;
            }
            else{
                ans[i] = t;
                t++;
            }
        }
        FOR(i, 0, n){
            cout << ans[i] << " ";
        }
        cout << endl;


    }


}
