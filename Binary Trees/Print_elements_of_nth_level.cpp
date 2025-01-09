#include<iostream>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void nthLevel(TreeNode* root, int curr, int level){
    if(root == NULL) return;
    if(curr == level){
        cout<<root->val<<" ";
        return;
    } 
    nthLevel(root->left, curr+1, level);
    nthLevel(root->right, curr+1, level);
}

int levels(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

void levelOrder(TreeNode* root){
    int n = levels(root);
    for(int i=1;i<=n;i++){
        nthLevel(root,1,i);
        cout<<endl;
    }
}

int main(){
    TreeNode* a = new TreeNode(10);
    TreeNode* b = new TreeNode(20);
    TreeNode* c = new TreeNode(30);
    TreeNode* d = new TreeNode(40);
    TreeNode* e = new TreeNode(50);
    TreeNode* f = new TreeNode(60);
    TreeNode* g = new TreeNode(70);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    levelOrder(a);
}