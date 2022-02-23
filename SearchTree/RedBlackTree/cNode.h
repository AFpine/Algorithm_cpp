//자유롭게 수정 되어도 된다.
const int RED = 0;
const int BLACK = 1;

class cRedBlackTree;

class cNode {
	friend class cRedBlackTree;
public:
	cNode();
	cNode(int t) { key = t; left = right = 0; color = RED; }
private:
	cNode* left;
	cNode* right;
	int key;
	int color;
};
