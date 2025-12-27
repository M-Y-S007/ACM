#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll exgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;

    ll x, y;
    exgcd(a, b, x, y);

    x = (x % b + b) % b;
    

    cout << x << endl;
    return 0;
}