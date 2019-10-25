/*
ID: andyyan1
PROG: heritage
LANG: C++
*/

#include <string>
#include <iostream>
#include <cassert>
#include <cstdio>
using namespace std;

string inOrder, preOrder;

void Input()
{
	cin >> inOrder >> preOrder;
}

string getPostOrder(string preOrder, string inOrder)
{
	//     cout<<preOrder<<' '<<inOrder<<endl;
	assert(preOrder.length() == inOrder.length());
	if (preOrder.length() == 1 || preOrder.length() == 0)
		return preOrder;
	int rootIdx;
	rootIdx = inOrder.find_first_of(preOrder[0]);
	assert(rootIdx != string::npos);
	string leftTree, rightTree;
	leftTree = getPostOrder(preOrder.substr(1, rootIdx), inOrder.substr(0, rootIdx));
	rightTree = getPostOrder(preOrder.substr(rootIdx + 1, preOrder.length() - rootIdx - 1), inOrder.substr(rootIdx + 1, preOrder.length() - rootIdx - 1));
	return leftTree + rightTree + preOrder[0];
}

void Solve()
{
	cout << getPostOrder(preOrder, inOrder) << endl;
}

int main()
{
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);

	Input();
	Solve();

	return 0;
}