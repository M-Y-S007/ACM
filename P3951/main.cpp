#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a, b;
    scanf("%lld%lld",&a, &b);
    ll ans =  a * b - a - b;
    printf("%lld",ans);
    return 0;
}