#include <iostream>
#include "cBinarySearchTree.h"
using namespace std;

int main() {
	char cmd;
	int n, x;
	cBinarySearchTree<int> tree;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd >> x;
		switch (cmd) {
		case 'I':
			tree.treeInsert(x);
			break;
		case 'D':
			tree.treeDelete(x);
			break;
		}
	}
	tree.treePrint();
	return 0;
}