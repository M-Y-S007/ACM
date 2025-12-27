#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y){
    if(y == 0){
        return x;
    }
    return gcd(y,x % y);
}
int main(){
    long long x, y;
    cin >> x >> y;
    if(y % x != 0){
        cout << 0 << endl;
        return 0;
    }

    long long k = y / x;
    int count  = 0;

    for(long long a = 1; a * a <= k; a++){
        if(k % a == 0){
            long long b = k / a;
            if(gcd(a,b) == 1){
                count += 2;
            }
        }
    }
    cout << count << endl;
    return 0;
}