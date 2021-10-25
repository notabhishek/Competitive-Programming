#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T, typename S> ostream &operator<<(ostream &os, const pair<T, S> &v);

class bstNode
{
public:
    int key, val;
    bstNode *left, *right;
    int height;

    bstNode(int key = 0, int val = 0,bstNode* left = NULL,bstNode* right = NULL)
    {
    	this->key = key;
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

bstNode *insert(bstNode *root, int key, int val)
{
    if (!root)
        return new bstNode(key, val);

    if (root->key == key)
    { // update
        root->val = val;
    }
    else if (root->key > key)
    {
        root->left = insert(root->left, key, val);
    }
    else
    {
        root->right = insert(root->right, key, val);
    }
    return root;
}

bstNode *search(bstNode *root, int key)
{
    if (!root)
        return NULL;
    if (root->key == key)
        return root;
    if (root->key > key)
        return search(root->left, key);
    return search(root->right, key);
}

bstNode* Delete (bstNode *root, int key)
{
    if (!root) 
        return NULL;
    if (root->key > key)
        root->left = Delete (root->left, key);
    else if (root->key < key)
        root->right = Delete (root->right, key);
    else
    {
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        if (!root->left) {
        	bstNode* right = root->right;
        	delete root;
            return right;
        }
        if (!root->right) {
        	bstNode *left = root->left;
        	delete root;
            return left;
        }
        // 2 children get inorder successor
        bstNode *inorderNext = root->right;
        while (inorderNext->left)
            inorderNext = inorderNext->left;

        root->key = inorderNext->key;
        root->val = inorderNext->val;
        root->right = Delete (root->right, inorderNext->key);
    }
    return root;
}

void inorder(bstNode *root) {
	if(!root) return ;
	inorder(root->left);
	cout << make_pair(root->key, root->val) << " ";
	inorder(root->right);
}
#define COUNT 10
void print2DUtil(bstNode *root, int space)
{
    if (root == NULL) return;
    space += COUNT;
    print2DUtil(root->right, space);
    cout<<endl;
    for (int i = COUNT; i < space; i++) cout<<" ";
    cout<<make_pair(root->key, root->val)<<"\n";
    print2DUtil(root->left, space);
}
void print2D(bstNode *root)
{
    print2DUtil(root, 0);
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		a[i] = rand()%100;
	}
	bstNode *root = NULL;
	cout << a << endl;
	for(int i = 0; i < n; ++i) {
		root = insert(root, a[i], i);
		cout << "insert " << make_pair(a[i], i) << "\n"; 
		print2D(root);
		cout << "\n\n\n";
	}
	int delKey = 24;
	bstNode *delVal = search(root, delKey); 
	cout << "delete " << make_pair(delKey, delVal? delVal->val : 0) << "\n"; 
	root = Delete(root, delKey);
	print2D(root);
	
	delKey = 69;
	delVal = search(root, delKey); 
	cout << "delete " << make_pair(delKey, delVal? delVal->val : 0) << "\n"; 
	root = Delete(root, delKey);
	print2D(root);
	
	delKey = 41;
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
