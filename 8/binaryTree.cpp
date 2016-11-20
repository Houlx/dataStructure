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
		return element;
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
			cout << root->element << endl;
			preOrder(root->LChild);
			preOrder(root->RChild);
		}
	}

	void inOrder(BinaryTreeNode<T>* root) {
		if (root != NULL)
		{
			inOrder(root->LChild);
			cout << root->element << endl;
			inOrder(root->RChild);
		}
	}


	void postOrder(BinaryTreeNode<T>* root) {
		if (root != NULL)
		{
			postOrder(root->LChild);
			postOrder(root->RChild);
			cout << root->element << endl;
		}
	}

	void preOrderWithoutRecusion(BinaryTreeNode<T>* root) {
		// using std::stack;

		stack<BinaryTreeNode<T>*> nodeStack;
		BinaryTreeNode<T>* pointer = root;

		while (!nodeStack.empty() || pointer) {
			if (pointer)
			{
				cout << pointer->element << endl;
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
				cout << pointer->element << endl;
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
				cout << pointer->element << endl;
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
//二叉搜索树 查找
template <class T>
BinaryTreeNode<T>* search(BinaryTreeNode<T>* root, T key) {
	bool find = false;
	BinaryTreeNode<T>* temp = root;
	while (temp!=NULL && !find) {
		if (key == temp->element) {
			find = true;
			return temp;
		}
		else if (key < temp->element) {
			temp = temp->LChild;
		}
		else {
			temp = temp->RChild;
		}
	}
	return NULL;
}

//insert Node
template <class T>
void insertNode(BinaryTreeNode<T>** root, const T& value) {
	BinaryTreeNode<T>* p = new BinaryTreeNode<T>(value);
	if ((*root) == NULL) {
		(*root) = p;
	}
	else if (value<(*root)->getValue()) {
		insertNode(&((*root)->LChild), value);
	}
	else {
		insertNode(&((*root)->RChild), value);
	}
}

//二叉搜索树 复制删除
template <class T>
void deleteByCopying(BinaryTreeNode<T>* root, const T& value) {
	BinaryTreeNode<T> *node = search(root, value);
	BinaryTreeNode<T> *tmp = node;
	BinaryTreeNode<T> *previous = node;
	if (node) {
		if (!node->RChild)
		{
			node = node->LChild;
		}
		else if (!node->LChild)
		{
			node = node->RChild;
		}
		else {
			tmp = node->LChild;
			previous = node;
			while (tmp->RChild) {
				previous = tmp;
				tmp = tmp->RChild;
			}
			node->element = tmp->element;
			if (previous == node)
			{
				previous->LChild = tmp->LChild;
			}
			else {
				previous->RChild = tmp->LChild;
			}
		}
	}
}
enum createTreeMethod {
	PRE_IN,
	POST_IN
};

template <class T>
void createTree(createTreeMethod method, BinaryTreeNode<T>** root, T arr1[], int i, int j, T arr2[], int k, int h) {
	int m, n;
	switch (method) {
		//先序，中序 构造二叉树
	case PRE_IN:
		(*root) = new BinaryTreeNode<T>();
		(*root)->element = arr1[i];

		m = k;
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
		//后序，中序 构造二叉树
	case POST_IN:
		(*root) = new BinaryTreeNode<T>();
		(*root)->element = arr2[h];

		n = i;
		while (arr2[h] != arr1[n]) {
			n++;
		}
		if (n == i)
		{
			(*root)->LChild = NULL;
		}
		else {
			createTree(POST_IN, &(*root)->LChild, arr1, i, n - 1, arr2, k, k + n - i - 1);
		}
		if (n == j) {
			(*root)->RChild = NULL;
		}
		else {
			createTree(POST_IN, &(*root)->RChild, arr1, n + 1, j, arr2, k + n - i, h - 1);
		}

		break;
	}
}

// void createTree
int main(int argc, char const *argv[])
{
	//test Function.
	BinaryTreeNode<int>* root0 = NULL;
	BinaryTreeNode<int>* root1 = NULL;
	int pre[] = { 100,80,60,90,120,140 };
	int in[] = { 60,80,90,100,120,140 };
	int post[] = { 60,90,80,140,120,100 };

	//1.create tree by pre and in
	createTree(PRE_IN, &root0, pre, 0, 5, in, 0, 5);
	BinaryTree<int> tree0(root0);
	cout << "1.create tree by pre and in:(pre order result)" << endl;
	tree0.preOrder(root0);
	cout << endl;

	//2.create tree by in and post
	createTree(POST_IN, &root1, in, 0, 5, post, 0, 5);
	BinaryTree<int> tree1(root1);
	cout << "2.create tree by in and post:(pre order result)" << endl;
	tree1.preOrder(root1);
	cout << endl;

	//3.insert node
	insertNode(&root0, 110);
	cout << "3.insert node 110:" << endl;
	tree0.preOrder(root0);
	cout << endl;

	//4.search node
	cout << "4.search node 120 and 70:" << endl;
	BinaryTreeNode<int>* test0 = NULL;
	BinaryTreeNode<int>* test1 = NULL;
	test0 = search(root0, 120);
	test1 = search(root0, 70);
	if (test0) {
		cout << test0->element << endl;
	}else{
		cout << "120 not found" << endl;
	}
	if (test1)
	{
		cout << test1->element << endl;
	}else{
		cout << "70 not found" << endl;
	}
	cout << endl;

	//5.delete node
	deleteByCopying(root0, 80);
	cout << "5.delete node 80:" << endl;
	tree0.preOrder(root0);
	cout << endl;

}