#include<iostream>
#include<vector>
using namespace std;
//If we are using array we need to pass size also
void dis1(int arr[], int n, int idx){
    if (idx == n) return;
    cout<<arr[idx]<<" ";
    dis1(arr,n,idx+1);
}
//by using vector we don't need to pass size
void dis2(vector<int> & v, int idx){
    if (idx == v.size()) return;
    cout<<v[idx]<<" ";
    dis2(v,idx+1);
} 

int main(){
    int arr[] = {2,1,6,3,9,0,2};
    int n = sizeof(arr)/(sizeof(arr[0]));
    dis1(arr,n,0);//array
    vector<int> v(n);
    cout<<""<<endl;
    for(int i=0;i<n;i++){
        v[i] = arr[i];
    }
    dis2(v,0);//vector
}