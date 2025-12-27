#include<iostream>
#include<cstdio>
using namespace std;
double a, b, c, d;
double fun(double x){
    return a*x*x*x + b*x*x + c*x + d;
}
double find(double l, double r){
    while(r - l > 1e-5){
        double mid = (l + r) / 2;
        if(fun(mid)*fun(r) < 0){
            l = mid;
        }
        else{
            r = mid;
        }
        
    }
    return (l + r) / 2;
}
int main(){
    scanf("%lf%lf%lf%lf",&a, &b, &c, &d);
    int count = 0;
    for(int i = -100; i < 100; i++){
        double y1 = fun(i), y2 = fun(i + 1);
        if(!y1){
            printf("%.2lf",(double)i);
            count++;
            if(count < 3) printf(" ");
        }
        else if(y1 * y2 < 0){
            double root = find(i, i + 1);
            printf("%.2lf",root);
            count++;
            if(count < 3) printf(" ");
        }
        if(count == 3) break;

    }   

    return 0;
}