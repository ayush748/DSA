#include <iostream>
#include <vector>
using namespace std;
int lowerBound(vector<int> &a, int x){
    int l = 0, r = a.size() - 1;
    int ans = a.size();

    while(l <= r){
        int mid = (l + r) / 2;

        if(a[mid] >= x){
            ans = mid;
            r = mid - 1; 
        }
        else{
            l = mid + 1;   
        }
     }
    return ans;
}

int upperBound(vector<int> &a, int x){
    int l = 0, r = a.size() - 1;
    int ans = a.size();

    while(l <= r){
        int mid = (l + r) / 2;

        if(a[mid] > x){
            ans = mid;
            r = mid - 1;   // move left
        }
        else{
            l = mid + 1;   // move right
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    cin >> x;

    int lb = lowerBound(a, x);
    int ub = upperBound(a, x);

    cout << "Lower Bound Index: " << lb << endl;
    cout << "Upper Bound Index: " << ub << endl;

    return 0;
}