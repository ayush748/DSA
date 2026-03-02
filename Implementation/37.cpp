#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

int main(){
    int n;
    cin >> n;

    cpp_int ans = 1;
    ans <<= n;   
    ans -= 1;   

    cout << ans;
    return 0;
}