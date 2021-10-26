#include <bits/stdc++.h>
using namespace std;


template <typename T> ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T, typename S> ostream &operator<<(ostream &os, const pair<T, S> &v);

class avlNode
{
public:
    int key, val;
    avlNode *l, *r;
    int h;

    avlNode(int key = 0, int val = 0,avlNode* l = NULL,avlNode* r = NULL)
    {
    	this->key = key;
        this->val = val;
        this->l = l;
        this->r = r;
        this->h = 1;
    }
};
int height(avlNode *root) {
	return root ? root->h : 0;
}
int balance(avlNode *root) {
	return root ? height(root->l) - height(root->r) : 0;
}

avlNode *leftRotate(avlNode *z) {
	/*
		z                                y
	 /  \                            /   \ 
	T1   y     Left Rotate(z)       z      x
	    /  \   - - - - - - - ->    / \    / \
	   T2   x                     T1  T2 T3  T4
	       / \
	     T3  T4
	*/	
	avlNode *y = z->r;
	z->r = y->l;
	y->l = z;
	
	z->h = 1 + max(height(z->l), height(z->r));
	y->h = 1 + max(height(y->l), height(y->r));
	return y;
}

avlNode *rightRotate(avlNode *z) {
	/*
		T1, T2, T3 and T4 are subtrees.
	         z                                      y 
	        / \                                   /   \
	       y   T4      Right Rotate (z)          x      z
	      / \          - - - - - - - - ->      /  \    /  \ 
	     x   T3                               T1  T2  T3  T4
	    / \
	  T1   T2
	*/
	avlNode *y = z->r;
	z->l = y->r;
	y->r = z;
	
	z->h = 1 + max(height(z->l), height(z->r));
	y->h = 1 + max(height(y->l), height(y->r));
	return y;
}

avlNode *insert(avlNode *root, int key, int val)
{
    if (!root)
        return new avlNode(key, val);

    if (root->key == key)
    { // update
        root->val = val;
        return root;
    }
    else if (root->key > key)
		root->l = insert(root->l, key, val);
    else
    	root->r = insert(root->r, key, val);
    
    // BST insertion complete now balance 
    root->h = 1 + max(height(root->l), height(root->r));
    
    // calculate balance factor 
    int bal = balance(root);
    if(abs(bal) <= 1) return root;
     
    if(bal > 1 && root->l->key > key) // LL case
    	return rightRotate(root);
    if(bal > 1 && root->l->key < key) { // LR case  
    	root->l = leftRotate(root->l); // now LL case
    	return rightRotate(root);
    }
    if(bal < -1 && root->r->key < key) // RR case 
    	return leftRotate(root);
    if(bal < -1 && root->r->key > key) { // RL case
    	root->r = rightRotate(root->r); // now RR case
    	return leftRotate(root);
    }
}

avlNode *search(avlNode *root, int key)
{
    if (!root)
        return NULL;
    if (root->key == key)
        return root;
    if (root->key > key)
        return search(root->l, key);
    return search(root->r, key);
}

avlNode* Delete (avlNode *root, int key)
{
    if (!root) 
        return NULL;
    if (root->key > key)
        root->l = Delete (root->l, key);
    else if (root->key < key)
        root->r = Delete (root->r, key);
    else
    {
        if (!root->l && !root->r) {
            delete root;
            return NULL;
        }
        if (!root->l) {
        	avlNode* r = root->r;
        	delete root;
            return r;
        }
        if (!root->r) {
        	avlNode *l = root->l;
        	delete root;
            return l;
        }
        // 2 children get inorder successor
        avlNode *inorderNext = root->r;
        while (inorderNext->l)
            inorderNext = inorderNext->l;

        root->key = inorderNext->key;
        root->val = inorderNext->val;
        root->r = Delete (root->r, inorderNext->key);
    }
    
    if(!root) return NULL;
    
    root->h = 1 + max(height(root->l), height(root->r));
    
    int bal = balance(root);
    
    if(abs(bal) <= 1) return root;
     
    if(bal > 1 && root->l->key < key) // LL case
    	return rightRotate(root);
    if(bal > 1 && root->l->key > key) { // LR case  
    	root->l = leftRotate(root->l); // now LL case
    	return rightRotate(root);
    }
    if(bal < -1 && root->r->key > key) // RR case 
    	return leftRotate(root);
    if(bal < -1 && root->r->key < key) { // RL case
    	root->r = rightRotate(root->r); // now RR case
    	return leftRotate(root);
    }
    return root;
}

void inorder(avlNode *root) {
	if(!root) return ;
	inorder(root->l);
	cout << make_pair(root->key, root->val) << " ";
	inorder(root->r);
}
#define COUNT 10
void print2DUtil(avlNode *root, int space)
{
    if (root == NULL) return;
    space += COUNT;
    print2DUtil(root->r, space);
    cout<<endl;
    for (int i = COUNT; i < space; i++) cout<<" ";
    cout<<make_pair(root->key,root->val)<<"\n";
    // cout<<make_pair(root->key,make_pair(root->val, root->h))<<"\n";
    print2DUtil(root->l, space);
}
void print2D(avlNode *root)
{
    print2DUtil(root, 0);
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		a[i] = i;
		// a[i] = rand()%100;
	}
	avlNode *root = NULL;
	cout << a << endl;
	for(int i = 0; i < n; ++i) {
		root = insert(root, a[i], i);
		cout << "insert " << make_pair(a[i], i) << "\n"; 
		print2D(root);
		cout << "\n\n\n";
	}
	int delKey = 0;
	avlNode *delVal = search(root, delKey); 
	cout << "delete " << make_pair(delKey, delVal? delVal->val : 0) << "\n"; 
	root = Delete(root, delKey);
	print2D(root);
	
	delKey = 2;
	delVal = search(root, delKey); 
	cout << "delete " << make_pair(delKey, delVal? delVal->val : 0) << "\n"; 
	root = Delete(root, delKey);
	print2D(root);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}


template <typename T> ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (i)
            os << ", ";
        os << v[i];
    }
    os << "]\n";
    return os;
}
template <typename T, typename S> ostream &operator<<(ostream &os, const pair<T, S> &v)
{
    os << "(";
    os << v.first << ", " << v.second << ")";
    return os;
}
