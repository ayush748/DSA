#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> arr;
int a;

int get1(int b){
    int i=0;
    while(i<arr.size()){
        if(arr[i].first==b){
            int c=arr[i].second;
            pair<int,int> d=arr[i];
            arr.erase(arr.begin()+i);
            arr.push_back(d);
            return c;
        }
        i++;
    }
    return -1;
}

void put1(int b,int c){
    int i=0;
    while(i<arr.size()){
        if(arr[i].first==b){
            arr.erase(arr.begin()+i);
            arr.push_back({b,c});
            return;
        }
        i++;
    }

    if(arr.size()==a){
        arr.erase(arr.begin());
        arr.push_back({b,c});
    }
    else{
        arr.push_back({b,c});
    }
}
int main(){
    int b;
    cin>>a>>b;

    while(b--){
        int c;
        cin>>c;

        if(c==1){
            int d,e;
            cin>>d>>e;
            put1(d,e);
        }
        else if(c==2){
            int d;
            cin>>d;
            cout<<get1(d)<<endl;
        }
    }
    return 0;
}