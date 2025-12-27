#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll a, ll b, ll p){
    ll res = 1 % p;
    a %= p;
    while(b){
        if(b & 1){
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, p;
    ll ans;
    cin >> a >> b >> p;
    ans = qpow(a, b, p);
    cout << a << "^" << b << " mod "<< p << "=" << ans << endl; 
    return 0;
}