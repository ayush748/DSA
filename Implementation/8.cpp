#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
unordered_map<string,int>mp={
    {"Tetrahedron",4},
    {"Cube",6},
    {"Octahedron",8},
    {"Dodecahedron",12},
    {"Icosahedron",20}
};
int main(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans+mp[arr[i]];
    }
    cout<<ans<<endl;
    return 0;
}