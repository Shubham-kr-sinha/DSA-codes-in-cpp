#include<iostream>
#include<stack>
#include<queue>
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

void inorder(TreeNode* root){
    stack<TreeNode*> st;
    vector<int> ans;
    TreeNode* node = root;
    while(st.size()>0 || node){
        if(node){
            st.push(node);
            node = node->left;
        }
        else{
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            node = temp->right;
        }
    }
    for(auto i: ans){
        cout<< i << " ";
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
    inorder(a);
}