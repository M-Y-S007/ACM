#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
int n;
ll a[maxn];
ll b[maxn];
ll exgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll d, x1, y1;
    d  = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a/b * y1;
    return d;
}
ll crt(ll m[], ll r[]){
    ll M = 1;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        M *= m[i];
    }
    for(int i = 1; i <= n; i++){
        ll c = M/m[i], x, y;
        exgcd(c, m[i], x, y);
        ans = (ans + r[i] * c * x % M) % M;
    }
    return (ans % M + M) % M;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    ll ans = crt(a, b);
    cout << ans << endl;
    return 0;
}