#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[50001];
int ans[50001];
int maxans[50001];
int main(){
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int x = 0; x < n; x++){
		cin >> a[x];
	}
	sort(a, a + n);
	for (int x = 0; x < n; x++){
		int l = x;
		int r = n - 1;
		int j = -1;
		while (l <= r){
			int mid = (l + r) / 2;
			if (a[mid] - a[x] <= k){
				l = mid + 1;
				j = mid;
			}
			else{
				r = mid - 1;
			}
		}
		if (j != -1)
		{
			ans[x] = j - x + 1;
		}
		else
		{
			ans[x] = 1;
		}
	}
	maxans[n - 1] = ans[n - 1];
	for (int x = n - 2; x >= 0; x--){
		maxans[x] = max(ans[x], maxans[x + 1]);
	}
	int ret = 0;
	for (int x = 0; x < n; x++){
		int cnt = ans[x];
		int j = x + ans[x];
		if (j < n){
			cnt += maxans[j];
		}
		ret = max(cnt, ret);
	}
	cout << ret << endl;
}