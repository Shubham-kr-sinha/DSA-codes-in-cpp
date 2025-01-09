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
        this->left = left;
        this->right = right;
    }
};

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
        if(arr[i] != INT_MIN) l = new TreeNode(arr[i]);
        else l = NULL;
        if(arr[j] != INT_MIN) r = new TreeNode(arr[j]);
        else r = NULL;
        temp->left = l;
        temp->right = r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i=i+2;
        j=j+2;
    }
    return root;

}

void leftboundary(TreeNode* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    cout<<root->val<<" ";
    if(root->left == NULL) leftboundary(root->right);
    leftboundary(root->left);
}

void bottomboundary(TreeNode* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) cout<<root->val<<" ";
    bottomboundary(root->left);
    bottomboundary(root->right);
}

void rightboundary(TreeNode* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    
    if(root->right == NULL) rightboundary(root->left);
    rightboundary(root->right);
    cout<<root->val<<" ";
}
// int levels(TreeNode* root){
//     if(root == NULL) return 0;
//     return 1+ max(levels(root->left),levels(root->right));
// }

// void nthlevel(TreeNode* root, int curr, int level){
//     if(root == NULL) return;
//     if(curr == level){
//         cout<<root->val<<" ";
//         return;
//     }
//     nthlevel(root->left, curr+1, level);
//     nthlevel(root->right, curr+1, level);
// }

// void lorder(TreeNode* root){
//     int n = levels(root);
//     for(int i=1;i<=n;i++){
//         nthlevel(root,1,i);
//         cout<<endl;
//     }
// }

void boundary(TreeNode* root){
    leftboundary(root);
    bottomboundary(root);
    rightboundary(root);
}

int main(){
    int arr[] = {1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr, n);
    // lorder(root); //Did this to check tree.
    boundary(root);
}