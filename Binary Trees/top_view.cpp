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
        i = i+2;
        j = j+2;
    }
    return root;
}

void horlevel(TreeNode* root, int& minlevel, int& maxlevel, int level){
    if(root == NULL) return;
    minlevel = min(minlevel, level);
    maxlevel = max(maxlevel, level);
    horlevel(root->left, minlevel, maxlevel, level-1);
    horlevel(root->right, minlevel, maxlevel, level+1);
}

void topview(vector<int>& top, TreeNode* root, int level){
    if(root== NULL) return;
    if(top[level] == INT_MIN) top[level] = root->val;
    topview(top,root->left,level-1);
    topview(top,root->right,level+1);
}

int main(){
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,9,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode* root = construct(arr,n);
    int minlevel = 0;
    int maxlevel = 0;
    horlevel(root, minlevel, maxlevel, 0);
    int horilevels = maxlevel - minlevel +1;
    vector<int> top(horilevels, INT_MIN);
    topview(top, root, -minlevel);
    for(int i=0;i< top.size(); i++){
        cout<<top[i]<<" ";
    }
}