
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> points;
int getArea(){
	int minX = 1000000000;
	int minY = 1000000000;
	int maxX = 0;
	int maxY = 0;
	for (int x = 0; x < points.size(); x++)	{
		minX = min(minX, points[x].first);
		minY = min(minY, points[x].second);
		maxX = max(maxX, points[x].first);
		maxY = max(maxY, points[x].second);
	}
	return (maxY - minY) * (maxX - minX);
}
int main()
{
	//freopen("reduce.in", "r", stdin);
	//freopen("reduce.out", "w", stdout);
	int n;
	cin >> n;
	for (int x = 0; x < n; x++){
		pair<int, int> point;
		cin >> point.first;
		cin >> point.second;
		points.push_back(point);
	}
	int k = 40000 * 40000;
	int ans = 1000000000;
	int ind = 0;
	int val = points[0].first;
	for (int x = 1; x < n; x++)	{
		if (points[x].first < val){
			val = points[x].first;
			ind = x;
		}
	}
	pair<int, int> erase = points[ind];
	points.erase(points.begin() + ind);
	ans = min(ans, getArea());
	points.push_back(erase);
	ind = 0;
	val = points[0].first;
	for (int x = 1; x < n; x++)	{
		if (points[x].first > val){
			val = points[x].first;
			ind = x;
		}
	}
	erase = points[ind];
	points.erase(points.begin() + ind);
	ans = min(ans, getArea());
	points.push_back(erase);
	ind = 0;
	val = points[0].second;
	for (int x = 1; x < n; x++){
		if (points[x].second < val){
			val = points[x].second;
			ind = x;
		}
	}
	erase = points[ind];
	points.erase(points.begin() + ind);
	ans = min(ans, getArea());
	points.push_back(erase);
	ind = 0;
	val = points[0].second;
	for (int x = 1; x < n; x++){
		if (points[x].second > val){
			val = points[x].second;
			ind = x;
		}
	}
	erase = points[ind];
	points.erase(points.begin() + ind);
	ans = min(ans, getArea());
	points.push_back(erase);
	cout << ans << endl;
	return 0;
}