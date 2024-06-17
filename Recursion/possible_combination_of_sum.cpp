// #include<iostream>
// #include<vector>
// using namespace std;

// void combination(vector<int> v, int a[], int n, int tar){
//     if (tar == 0){
//         for(int i=0;i<v.size();i++){
//             cout<<v[i]<<" ";
//         }
//         cout<<endl;
//         return;
//     }
//     if (tar<0) return;
//     for(int i=0;i<n;i++){
//         v.push_back(a[i]);
//         combination(v,a,n,tar-a[i]);
//         v.pop_back();
//     }
// }

// int main(){
//     int arr[] = {2,3,5};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int target = 8;
//     vector<int> v;
//     combination(v,arr,n,target);
// }

//The above code will give repeated possible combinatations as if 3 is pushed into the vector then again it pushes 2 into the vector 
//further which will result in repetition of solutions.
// To avoid this we have to make sure that when 3 is pushed into the vector then 2 is not called. 
//Similarly when 5 is pushed into the vector then 2 and 3 are not called.

#include<iostream>
#include<vector>
using namespace std;

void combination(vector<int> v, int a[], int n, int tar, int idx){
    if (tar == 0){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if (tar<0) return;
    for(int i=idx;i<n;i++){
        v.push_back(a[i]);
        combination(v,a,n,tar-a[i],i);
        v.pop_back();
    }
}

int main(){
    int arr[] = {2,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 8;
    vector<int> v;
    combination(v,arr,n,target,0);
}