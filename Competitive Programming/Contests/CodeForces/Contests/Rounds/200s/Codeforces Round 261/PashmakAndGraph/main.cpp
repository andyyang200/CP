#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, int> > edges[100010];
int d[300010];
int n;
int m;

int main()
{
    cin >> n >> m;
    for (int x = 0; x < m; x++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[w].push_back(make_pair(u, v));
    }

    int max = 0;
    int temp[300010];
    for (int x = 0; x < 100010; x++)
    {
        for (int i = 0; i < edges[x].size(); i++)
        {
            int u = edges[x][i].first;
            int v = edges[x][i].second;
            temp[v] = 0;
        }
        for (int i = 0; i < edges[x].size(); i++)
        {
            int u = edges[x][i].first;
            int v = edges[x][i].second;
            temp[v] = std::max(std::max(d[v], d[u] + 1), temp[v]);
            max = std::max(temp[v], max);
        }
        for (int i = 0; i < edges[x].size(); i++)
        {
            int v = edges[x][i].second;
            d[v] = temp[v];
        }
    }
    cout << max << endl;
    return 0;
}
