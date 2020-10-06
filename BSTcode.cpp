#include<bits/stdc++.h>
#define crap ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
//#define int ll

using namespace std;

//BST implementation

class BST{
public:
	int data;BST* left;BST* right;
public:
	BST();//default constructor
	BST(int); //parameterised constructor
	BST* insert(BST *,int);
	BST* deleteNode(BST* ,int key);
	BST* minVal(BST* );
	int search(BST* ,int);
};

int BST::search(BST* root,int val){
	if(root==NULL) return 0;
	if(root->data == val) return 1;
	if(root->data < val){
		return search(root->right,val);
	}
	return search(root->left, val);
}

BST::BST(){
	data = 0;
	left = right = NULL;
}

BST::BST(int key){
	data = key;
	left = right = NULL;
}

BST* BST::insert(BST* root,int val){
	if(root == NULL){
		root =new BST(val);
		return root;
	}
	if(val > root->data){
		root->right = insert(root->right, val);
	}
	else{
		root->left = insert(root->left,val);
	}
}

BST* BST::minVal(BST* root){
	BST* cur = root;
	while(cur && cur->left!=NULL) cur = cur->left;
	return cur;
}

BST* BST::deleteNode(BST* root, int val){
	if(val < root->data)
		root->left = deleteNode(root->left,val);
	else if(val > root->data){
		root->right = deleteNode(root->right,val);
	}
	else{
		//if it has no child or one child
		if(root->left==NULL){
			BST* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			BST* temp = root->left;
			free(root);
			return temp;
		}
		else{
			BST* temp = minVal(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
	return root;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
   
    crap;
    BST  *root = NULL; 
    root = root->insert(root, 50); 
    root->insert(root, 30); 
    root->insert(root, 20); 
    root->insert(root, 40); 
    cout<<root->search(root, 20)<<endl;
    cout<<root->search(root, 10)<<endl;

    root->deleteNode(root,20);
    cout<<root->search(root, 20)<<endl;
    root->insert(root,20);
    cout<<root->search(root, 20)<<endl;

}


