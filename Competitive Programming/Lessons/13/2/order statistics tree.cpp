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
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost; // order statistics tree
int main(void)
{
	ost X;
	X.insert(1);
	X.insert(2);
	X.insert(4);
	X.insert(8);
	X.insert(16);

	cout << *X.find_by_order(1) << endl; // 2
	cout << *X.find_by_order(2) << endl; // 4
	cout << *X.find_by_order(4) << endl; // 16

	cout << X.order_of_key(-5) << endl;  // 0
	cout << X.order_of_key(1) << endl;   // 0
	cout << X.order_of_key(3) << endl;   // 2
	cout << X.order_of_key(4) << endl;   // 2
	cout << X.order_of_key(400) << endl; // 5

}