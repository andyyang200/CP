#include <vector>
#include <algorithm>

using namespace std;
void
warshall_floyd(vector<vector<int> >&cost) {
	int N = (int)cost.size();
	for (int k = 0; k<N; ++k) {
		for (int i = 0; i<N; ++i) {
			for (int j = 0; j<N; ++j) {
				if (cost[i][k] != INT_MAX && cost[k][j] != INT_MAX)
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
}