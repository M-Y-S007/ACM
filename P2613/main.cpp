#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 19260817;

ll read_mod(){
    string s;
    cin >> s;
    ll res = 0;
    for(char c : s){
        res = (res * 10 + (c - '0')) % MOD;
    }
    return res;
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

ll inv(ll a){
    ll x, y;
    ll d = exgcd(a, MOD, x, y);
    if(d != 1) return -1;
    return (x % MOD + MOD) % MOD;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a = read_mod();
    ll b = read_mod();

    if(b == 0){
        cout << "Angry!" << endl;
        return 0;
    }

    ll b_inv = inv(b);


    if(b_inv == -1){
        cout << "Angry!" << endl;
        return 0;
    }
    ll ans = a * b_inv % MOD;

    cout << ans << endl;
    return 0;
}