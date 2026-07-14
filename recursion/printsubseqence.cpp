#include<iostream>
#include<vector>
using namespace std;
void printSubsequnce(int i,vector<int>&arr,vector<int>&ds){
    if(i==arr.size()){
        if(ds.empty()){
            cout<<"{}";
        }else{
            for(auto x:ds){
                cout<<x<<" ";
            }
        }
        cout<<endl;
        return ;
    }
    ds.push_back(arr[i]);
    printSubsequnce(i+1,arr,ds);
    ds.pop_back();
    printSubsequnce(i+1,arr,ds);

}
int main(){
    vector<int>arr={1,2,3};
    vector<int>ds;
    printSubsequnce(0,arr,ds);
    return 0;
}