#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll func(ll n){
    ll count = 0;
    ll t = n;
    for(int i = 1; i <= t; i++){
        if(n % i == 0){
            count++;
        }
    }
    if(t * t == n){
        return 2 * count + 1;
    }else{
        return 2 * count;
    }
}
ll sum(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 3;
    }
    return sum(n - 1) + func(n);
}
int main(){
    ll n;
    scanf("%d",&n);
    printf("%d",sum(n));
    return 0;
}