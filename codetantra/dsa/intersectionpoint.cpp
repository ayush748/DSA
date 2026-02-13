#include <iostream>
using namespace std;

bool findPoint(double x1,double y1,double x2,double y2,
               double x3,double y3,double x4,double y4,
               double &x,double &y){

    double A1 = y2-y1;
    double B1 = x1-x2;
    double C1 = A1*x1 + B1*y1;

    double A2 = y4-y3;
    double B2 = x3-x4;
    double C2 = A2*x3 + B2*y3;

    double det = A1*B2 - A2*B1;
    if(det==0) return false;   // parallel

    x = (B2*C1 - B1*C2)/det;
    y = (A1*C2 - A2*C1)/det;
    return true;
}

int main(){
    double x1,y1,x2,y2,x3,y3,x4,y4;
    double xi, yi;

    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;

    if(findPoint(x1,y1,x2,y2,x3,y3,x4,y4,xi,yi))
        cout<<"Intersection = "<<xi<<" "<<yi;
    else
        cout<<"Lines are Parallel";

    return 0;
}