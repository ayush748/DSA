// #include<iostream>
// #include<vector>
// using namespace std;
// class node{
//     public:
//     int val;
//     node* left;
//     node* right;
//     node(int data){
//         this->val=data;
//         this->right=data;1` 1
//     }
// };
// int main(){
    
//     return 0;
// }
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    return 0;
}