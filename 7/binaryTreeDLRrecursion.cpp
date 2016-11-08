template <class T>
class BinaryTreeNode{
public:
	T element;
	BinaryTreeNode<T> *LChild;
	BinaryTreeNode<T> *RChild;
	BinaryTreeNode<T> *parent;

	BinaryTreeNode(){
		element=0;
		LChild=NULL;
		RChild=NULL;
		parent=NULL;
	}
	BinaryTreeNode(const T& ele){
		element=ele;
		LChild=NULL;
		RChild=NULL;
		parent=NULL;
	}
	BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l,BinaryTreeNode<T>* r,BinaryTreeNode<T>* p){
		element=ele;
		LChild=l;
		RChild=r;
		parent=p;
	}
	BinaryTreeNode<T>* getLeftChild() const{
		return this->LChild;
	}
	BinaryTreeNode<T>* getRightChild() const{
		return this->RChild;
	}
	void setLeftChild(BinaryTreeNode<T>* l){
		this->LChild=l;
	}
	void setRightChild(BinaryTreeNode<T>* r){
		this->RChild=r;
	}
	T getValue() const{
		return this->element;
	}
	void setValue(const T& val){
		this->element=val;
	}
	bool isLeaf() const{
		if (this->LChild==NULL&&this->RChild==NULL)
		{
			return true;
		}
		return false;
	}
};

template <class T>
class BinaryTree{
private:
	BinaryTreeNode<T> *root;
public:
	BinaryTree(){
		root=NULL;
	}
	~BinaryTree();
	bool isEmpty() const{
		if (root==NULL)
		{
			return true;
		}
		return false;
	}
	BinaryTreeNode<T>* getRoot() const{
		return root;
	}
	BinaryTreeNode<T>* getParent(BinaryTreeNode<T>* current) const{
		if (current->parent)
		{
			return current->parent;
		}
		return NULL;
	}
	BinaryTreeNode<T>* getLeftSibling(BinaryTreeNode<T>* current) const{
		if (current->parent&&current->parent->LChild)
		{
			return current->parent->LChild;
		}
		return NULL;
	}
	BinaryTreeNode<T>* getRightSibling(BinaryTreeNode<T>* current) const{
		if (current->parent&&current->parent->RChild)
		{
			return current->parent->RChild;
		}
		return NULL;
	}
	void breadthFirstOrder(BinaryTreeNode<T>* root);
	void preOrder(BinaryTreeNode<T>* root);

	// void inOrder(BinaryTreeNode<T>* root);
	// void postOrder(BinaryTreeNode<T>* root);
	// void levelOrder(BinaryTreeNode<T>* root);
	// void deleteBinaryTree(BinaryTreeNode<T>* root);
};

int main(int argc, char const *argv[])
{
	
	return 0;
}