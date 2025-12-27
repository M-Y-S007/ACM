#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long t = sqrt(n);
    for(int i = 2; i <= t; i++){
        if(n % i == 0){
            cout << n / i ;
            break;
        }
    }
    return 0;
}