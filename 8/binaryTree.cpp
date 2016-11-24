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
	while (temp != NULL && !find) {
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
	else if (value < (*root)->getValue()) {
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

template <class T>
int degreeIs1(BinaryTreeNode<T>* root) {
	int i = 0;
	if (NULL != root)
	{
		if ((NULL != root->LChild && NULL == root->RChild) || (NULL != root->RChild && NULL == root->LChild))
		{
			i = 1 + degreeIs1(root->LChild) + degreeIs1(root->RChild);
		}
		else {
			i = degreeIs1(root->LChild) + degreeIs1(root->RChild);
		}
	}
	return i;
}

template <class T>
int degreeIs2(BinaryTreeNode<T>* root) {
	int i = 0;
	if (root)
	{
		if ((NULL != root->LChild) && (NULL != root->RChild))
		{
			i = 1 + degreeIs2(root->LChild) + degreeIs2(root->RChild);
		}
		else {
			i = degreeIs2(root->LChild) + degreeIs2(root->RChild);
		}
	}
	return i;
}

template <class T>
int leafNode(BinaryTreeNode<T>* root) {
	int i = 0;
	if (root)
	{
		if (NULL == root->LChild && NULL == root->RChild)
		{
			i = 1;
		}
		else {
			i = leafNode(root->LChild) + leafNode(root->RChild);
		}
	}
	return i;
}

template <class T>
int height(BinaryTreeNode<T>* root) {
	if (!root)
	{
		return 0;
	}
	else {
		return height(root->LChild) > height(root->RChild) ? height(root->LChild) + 1 : height(root->RChild) + 1;
	}
}

template <class T>
void nodeInOneDepth(BinaryTreeNode<T>* node, int depth, int curDepth, int* pnums) {
	if (!node || curDepth > depth) {
		return;
	}
	else if (curDepth < depth) {
		nodeInOneDepth(node->LChild, depth, curDepth + 1, pnums);
		nodeInOneDepth(node->RChild, depth, curDepth + 1, pnums);
	}
	else {
		(*pnums)++;
	}
}
template <class T>
int width(BinaryTreeNode<T>* root) {
	int h = height(root);
	int w = 0, maxWidth = 0, depth = 1;

	for (int i = 1; i <= h; i++) {
		w = 0;
		nodeInOneDepth(root, i, 1, &w);
		if (w > maxWidth)
		{
			maxWidth = w;
			depth = i;
		}
	}
	return maxWidth;
}

template <class T>
int findMaxValue(BinaryTreeNode<T>* root) {
	static int maxValue = 0;
	if (root)
	{
		if (root->getValue() > maxValue)
		{
			maxValue = root->getValue();
		}
		findMaxValue(root->LChild);
		findMaxValue(root->RChild);
	}
	return maxValue;
}

template <class T>
void revert(BinaryTreeNode<T>* root) {
	BinaryTreeNode<T> *temp;
	if (root)
	{
		temp = root->LChild;
		root->LChild = root->RChild;
		root->RChild = temp;
		revert(root->LChild);
		revert(root->RChild);
	}
}

template <class T>
void deleteLeaf(BinaryTreeNode<T>* root) {
	if (root) {
		if (root->LChild) {
			if (root->LChild->LChild || root->LChild->RChild) {
				deleteLeaf(root->LChild);
			} else {
				delete root->LChild;
				root->LChild = NULL;
			}
		}
		if (root->RChild)
		{
			if (root->RChild->LChild || root->RChild->RChild)
			{
				deleteLeaf(root->RChild);
			} else {
				delete root->RChild;
				root->RChild = NULL;
			}
		}
	}
}

template <class T>
bool isCompletedTree(BinaryTreeNode<T>* root) {
	queue<BinaryTreeNode<T>*> q;

	if (root)
	{
		q.push(root);
		BinaryTreeNode<T>* cur = NULL;
		bool flag = false;
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			if (cur) {
				if (flag) {
					return false;
				}
				q.push(cur->LChild);
				q.push(cur->RChild);
			} else {
				flag = true;
			}
		}
		return true;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	//test Function.
	BinaryTreeNode<int>* root0 = NULL;
	BinaryTreeNode<int>* root1 = NULL;
	int pre[] = { 100, 80, 60, 90, 120, 140 };
	int in[] = { 60, 80, 90, 100, 120, 140 };
	int post[] = { 60, 90, 80, 140, 120, 100 };

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
	}
	else {
		cout << "120 not found" << endl;
	}
	if (test1)
	{
		cout << test1->element << endl;
	}
	else {
		cout << "70 not found" << endl;
	}
	cout << endl;

	//5.delete node
	deleteByCopying(root0, 80);
	cout << "5.delete node 80:" << endl;
	tree0.preOrder(root0);
	cout << endl;

	//141页第五题（1）统计度为1的结点个数
	cout << "统计度为1的结点个数" << endl;
	cout << degreeIs1(root1) << endl;
	cout << endl;

	//（2）统计度为2的结点个数
	cout << "统计度为2的结点个数" << endl;
	cout << degreeIs2(root1) << endl;
	cout << endl;

	//（3）统计叶节点（度为0）的节点个数
	cout << "统计度为0的结点（叶节点）个数" << endl;
	cout << leafNode(root1) << endl;
	cout << endl;

	//（4）统计二叉树的高度
	cout << "统计二叉树的高度" << endl;
	cout << height(root1) << endl;
	cout << endl;

	//（5）统计二叉树的宽度，即在二叉树的各层上具有结点数最多的那一层上的结点总数
	cout << "统计宽度" << endl;
	cout << width(root1) << endl;
	cout << endl;

	//（6）计算二叉树中各结点中的最大元素的值
	cout << "结点中最大元素的值" << endl;
	cout << findMaxValue(root1) << endl;
	cout << endl;

	//（7）交换每个结点的左孩子结点和右孩子结点
	cout << "交换左右子结点" << endl;
	revert(root1);
	tree1.preOrder(root1);
	cout << endl;


	//（8）从二叉树中删除所有叶子结点
	cout << "删除所有叶子结点" << endl;
	deleteLeaf(root1);
	tree1.preOrder(root1);
	cout << endl;

	//141页第六题：编写算法判定给定二叉树是否为完全二叉树
	cout << "判断是否是完全二叉树" << endl;
	cout << isCompletedTree(root1) << endl;
	cout << endl;
}