//Andy Yang
#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

ll weight[400005][30];
int parent[400005][30];
int main(void)
{
	int q;
	cin >> q;
	ll last = 0;
	FOR(i, 1, 400001){
        FOR(j, 0, 21){
            parent[i][j] = -1;
        }
	}
	int cnt = 1;
	FOR(i, 0, q){
        int t, p, q;
        scanf("%d%d%d", &t, &p, &q);
        p ^= last;
        q ^= last;
        if (t == 1){
            RFOR(j, 20, -1){
                if (parent[p][j] != -1 && weight[parent[p][j]][j] < q){
                    p = parent[p][j];
                }
            }
            p = parent[p][0];
            parent[++cnt][0] = p;
            weight[cnt][0] = q;
            FOR(j, 1, 21){
                parent[cnt][j] = parent[parent[cnt][j - 1]][j - 1];
                weight[cnt][j] = weight[cnt][j - 1] + weight[parent[cnt][j - 1]][j - 1];
            }
        }
        else{
            int ans = 0;
            RFOR(j, 20, -1){
                if (parent[p][j] != -1 && weight[p][j] <= q){
                    q -= weight[p][j];
                    ans += 1 << j;
                }
            }
            printf("%d\n", ans);
            last = ans;
        }
	}
}
