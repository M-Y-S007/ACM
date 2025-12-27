#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll x, ll y){
    if(y == 0){
        return x;
    }
    return gcd(y, x % y);
}
ll lcm(ll x, ll y){
    if(x == 0 || y == 0){
        return 0;
    }
    return x * y / gcd(x, y);
}
int main(){
    ll n;
    scanf("%ll",&n);
    while(n--){
        ll count = 0;
        ll a0, a1, b0, b1;
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        for(ll i = a1; i <= b1; i++){
            if(gcd(i, a0) == a1 && lcm(i, b0) == b1){
                count ++;
            }
        }
        printf("%ll\n",count);
    }
    return 0;
}