#include <iostream>
#include <stack>
#include <queue>
using namespace std;
template <class T>
class BinaryTreeNode {
public:
	T element;
	BinaryTreeNode<T> *LChild;
	BinaryTreeNode<T> *RChild;
	BinaryTreeNode<T> *parent;

	BinaryTreeNode() {
		element = 0;
		LChild = NULL;
		RChild = NULL;
		parent = NULL;
	}
	BinaryTreeNode(const T& ele) {
		element = ele;
		LChild = NULL;
		RChild = NULL;
		parent = NULL;
	}
	BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r, BinaryTreeNode<T>* p) {
		element = ele;
		LChild = l;
		RChild = r;
		parent = p;
	}
	BinaryTreeNode<T>* getLeftChild() const {
		return this->LChild;
	}
	BinaryTreeNode<T>* getRightChild() const {
		return this->RChild;
	}
	void setLeftChild(BinaryTreeNode<T>* l) {
		this->LChild = l;
	}
	void setRightChild(BinaryTreeNode<T>* r) {
		this->RChild = r;
	}
	T getValue() const {
		return this->element;
	}
	void setValue(const T& val) {
		this->element = val;
	}
	bool isLeaf() const {
		if (this->LChild == NULL && this->RChild == NULL)
		{
			return true;
		}
		return false;
	}
};

template <class T>
class BinaryTree {
private:
	BinaryTreeNode<T> *root;
public:
	BinaryTree() {
		root = NULL;
	}
	BinaryTree(BinaryTreeNode<T>* root) {
		this->root = root;
	}
	bool isEmpty() const {
		if (root == NULL)
		{
			return true;
		}
		return false;
	}
	BinaryTreeNode<T>* getRoot() const {
		return root;
	}
	BinaryTreeNode<T>* getParent(BinaryTreeNode<T>* current) const {
		if (current->parent)
		{
			return current->parent;
		}
		return NULL;
	}
	BinaryTreeNode<T>* getLeftSibling(BinaryTreeNode<T>* current) const {
		if (current->parent && current->parent->LChild)
		{
			return current->parent->LChild;
		}
		return NULL;
	}
	BinaryTreeNode<T>* getRightSibling(BinaryTreeNode<T>* current) const {
		if (current->parent && current->parent->RChild)
		{
			return current->parent->RChild;
		}
		return NULL;
	}

	void breadthFirstOrder(BinaryTreeNode<T>* root) {
		// using std::queue;
		queue<BinaryTreeNode<T>*> nodeQueue;
		BinaryTreeNode<T>* pointer = root;

		if (pointer)
		{
			nodeQueue.push(pointer);
		}
		while (!nodeQueue.empty()) {
			pointer = nodeQueue.front();
			cout << pointer->element;
			nodeQueue.pop();
			if (pointer->LChild)
			{
				nodeQueue.push(pointer->LChild);
			}
			if (pointer->RChild)
			{
				nodeQueue.push(pointer->RChild);
			}
		}
	}
	void preOrder(BinaryTreeNode<T>* root) {
		if (root != NULL)
		{
			cout << root->element;
			preOrder(root->LChild);
			preOrder(root->RChild);
		}
	}

	void inOrder(BinaryTreeNode<T>* root) {
		if (root != NULL)
		{
			inOrder(root->LChild);
			cout << root->element;
			inOrder(root->RChild);
		}
	}


	void postOrder(BinaryTreeNode<T>* root) {
		if (root != NULL)
		{
			postOrder(root->LChild);
			postOrder(root->RChild);
			cout << root->element;
		}
	}

	void preOrderWithoutRecusion(BinaryTreeNode<T>* root) {
		// using std::stack;

		stack<BinaryTreeNode<T>*> nodeStack;
		BinaryTreeNode<T>* pointer = root;

		while (!nodeStack.empty() || pointer) {
			if (pointer)
			{
				cout << pointer->element;
				if (pointer->RChild != NULL)
				{
					nodeStack.push(pointer->RChild);
				}
				pointer = pointer->LChild;
			}
			else {
				pointer = nodeStack.top();
				nodeStack.pop();
			}
		}
	}

	void inOrderWithoutRecusion(BinaryTreeNode<T>* root) {
		// using std::stack;

		stack<BinaryTreeNode<T>*> nodeStack;
		BinaryTreeNode<T>* pointer = root;

		while (!nodeStack.empty() || pointer) {
			if (pointer)
			{
				nodeStack.push(pointer);
				pointer = pointer->LChild;
			}
			else {
				pointer = nodeStack.top();
				cout << pointer->element;
				pointer = pointer->RChild;
				nodeStack.pop();
			}
		}
	}

	void postOrderWithoutRecusion(BinaryTreeNode<T>* root) {
		// using std::stack;
		stack<BinaryTreeNode<T>*> nodeStack;
		BinaryTreeNode<T>* pointer = root;
		BinaryTreeNode<T>* pre = root;

		while (pointer) {
			for (; pointer->LChild != NULL; pointer = pointer->LChild) {
				nodeStack.push(pointer);
			}
			while (pointer != NULL && (pointer->RChild == NULL || pointer->RChild == pre)) {
				cout << pointer->element;
				pre = pointer;
				if (nodeStack.empty())
				{
					return;
				}
				pointer = nodeStack.top();
				nodeStack.pop();
			}
			nodeStack.push(pointer);
			pointer = pointer->RChild;
		}
	}
	// void deleteBinaryTree(BinaryTreeNode<T>* root);
};

int main(int argc, char const *argv[])
{
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	BinaryTree<int> tree(root);

	root->LChild = new BinaryTreeNode<int>(2);
	root->RChild = new BinaryTreeNode<int>(3);
	root->LChild->LChild = new BinaryTreeNode<int>(4);
	root->LChild->RChild = new BinaryTreeNode<int>(5);
	root->RChild->LChild = new BinaryTreeNode<int>(6);
	root->RChild->RChild = new BinaryTreeNode<int>(7);

	tree.breadthFirstOrder(root);
	cout << endl;

	tree.preOrder(root);
	cout << endl;
	tree.inOrder(root);
	cout << endl;
	tree.postOrder(root);
	cout << endl;

	tree.preOrderWithoutRecusion(root);
	cout << endl;
	tree.inOrderWithoutRecusion(root);
	cout << endl;
	tree.postOrderWithoutRecusion(root);
	return 0;
}