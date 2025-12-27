#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll L, n, m, x, y;
ll c, d;
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}
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
    cin >> x >> y >> m >> n >> L;
    ll a = m - n;
    ll b = y - x;

    if(a < 0){
        a = -a;
        b = -b; 
    }
    if(a == 0){
        if(b == 0){
            cout << 0 << endl;
        }else{
            cout << "Impossible" << endl;
        }
        return 0;
    }

    ll g = gcd(a, L);
    if( b % g != 0){
        cout << "Impossible" << endl;
        return 0;
    }

    ll t, k;
    exgcd(a, L, t, k);

    t = t * (b / g);
    ll mod = L / g;
    t = (t % mod + mod) % mod;
    cout << t << endl;
}