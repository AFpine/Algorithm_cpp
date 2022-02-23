#include "cNode.h"
#include <iostream>
using namespace std;

class cRedBlackTree {
public:
	//이부분의 양식은 반드시 지켜져야한다.
	cRedBlackTree();
	~cRedBlackTree();
	void treeInsert(int d);
	void treeDelete(int d);
	void treePrint();
private:
	cNode* root;
	cNode* nil;

	//public에 있는 멤버 함수를 위해 자유롭게 구현한다. 
};
