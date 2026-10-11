#include <iostream>
#include <vector>
using namespace std;
void traversal(vector<int>& arr) {
    for (int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
    cout << endl;
}
int searching(vector<int>&arr,int x) {
    for (int i=0;i<arr.size();i++) {
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}
void insertion(vector<int>& arr,int pos,int x) {
    if (pos < 0 || pos>arr.size()){
        cout << "No" << endl;
        return;
    }
    arr.push_back(0);
    for (int i=arr.size()-1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = x;
}
void deletion(vector<int>& arr, int pos) {
    if (pos < 0 || pos >= arr.size()) {
        cout << "No" << endl;
        return;
    }
    for (int i = pos; i < arr.size() - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr.pop_back(); 
}
void updation(vector<int>& arr,int pos,int x) {
    if (pos<0 || pos>=arr.size()){
        cout<<"No"<<endl;
        return;
    }
    arr[pos] = x;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    traversal(arr);
    int x;
    cin >> x;
    int index=searching(arr,x);
    if (index != -1)
        cout<<index<<endl;
    else{
        cout<<"Element not found"<<endl;
    }
    int pos,value;
    cout<<"Enter position and value to insert: ";
    cin>>pos>>value;
    insertion(arr, pos, value);
    cout << "After insertion: ";
    traversal(arr);
    cout << "Enter position to delete: ";
    cin >> pos;
    deletion(arr, pos);
    cout << "After deletion: ";
    traversal(arr);
    cout << "Enter position and new value: ";
    cin >> pos >> value;
    updation(arr, pos, value);
    cout << "After updation: ";
    traversal(arr);
    return 0;
}