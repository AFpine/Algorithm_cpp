#include "cNode.h"
#include <iostream>
using namespace std;

class cRedBlackTree {
public:
	//�̺κ��� ����� �ݵ�� ���������Ѵ�.
	cRedBlackTree();
	~cRedBlackTree();
	void treeInsert(int d);
	void treeDelete(int d);
	void treePrint();
private:
	cNode* root;
	cNode* nil;

	//public�� �ִ� ��� �Լ��� ���� �����Ӱ� �����Ѵ�. 
};
