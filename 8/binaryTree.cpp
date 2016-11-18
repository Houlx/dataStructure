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

enum createTreeMethod {
	PRE_IN,
	POST_IN
};
template <class T>
void createTree(createTreeMethod method, BinaryTreeNode<T>** root, T arr1[], int i, int j, T arr2[], int k, int h) {
	switch (method) {
	case PRE_IN:
		(*root) = new BinaryTreeNode<T>();
		(*root)->element = arr1[i];

		int m = k;
		while (arr1[i] != arr2[m]) {
			m++;
		}
		if (m == k)
		{
			(*root)->LChild = NULL;
		}
		else {
			createTree(PRE_IN, &(*root)->LChild, arr1, i + 1, i + m - k, arr2, k, m - 1);
		}
		if (m == h) {
			(*root)->RChild = NULL;
		}
		else {
			createTree(PRE_IN, &(*root)->RChild, arr1, i + m - k + 1, j, arr2, m + 1, h);
		}
		break;

	}
}

// void createTree
int main(int argc, char const *argv[])
{
	BinaryTreeNode<int>* root = NULL;

	int pre[] = { 1, 2, 4, 5, 3, 6, 7 };
	int in[] = { 4, 2, 5, 1, 6, 3, 7 };
	int post[] = {4, 5, 2, 6, 7, 3, 1};

	createTree(PRE_IN, &root, pre, 0, 6, in, 0, 6);

	BinaryTree<int> tree(root);
	tree.preOrder(root);
	cout << endl;
	tree.inOrder(root);
}