#include<iostream>
#include<queue>
#include<climits>
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

int levels(TreeNode* root){
    if(root == NULL) return 0;
    return 1+ max(levels(root->left),levels(root->right));
}

void nthlevel(TreeNode* root, int curr, int level){
    if(root == NULL) return;
    if(curr == level){
        cout<<root->val<<" ";
        return;
    }
    nthlevel(root->left, curr+1, level);
    nthlevel(root->right, curr+1, level);
}

void lorder(TreeNode* root){
    int n = levels(root);
    for(int i=1;i<=n;i++){
        nthlevel(root,1,i);
        cout<<endl;
    }
}

TreeNode* construct(int arr[], int n){
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n){
        TreeNode* temp = q.front();
        q.pop();
        TreeNode* l;
        TreeNode* r;
        if(arr[i]!=INT_MIN) l = new TreeNode(arr[i]);
        else l = NULL;
        if(arr[j]!=INT_MIN) r = new TreeNode(arr[j]);
        else r = NULL;
        temp->left = l;
        temp->right = r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i = i+2;
        j = j+2;
    }
    return root;
}

int main(){
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    lorder(root);
    
}
