template <typename T>
class cBinarySearchTree;

template <typename T>
class cNode {
	friend class cBinarySearchTree<T>;
public:
	cNode();
	cNode(T t) { key = t; left = right = nullptr; }		//constructor
private:
	cNode<T>* left;
	cNode<T>* right;
	T key;
};