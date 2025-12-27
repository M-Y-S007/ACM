#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        if(a == 0 && b == 0){
            if(x == 0 && y == 0){
                cout << "Y\n";
            }else{
                cout << "N\n";
            }
            continue;
        }

        ll g = gcd(a, b);

        if(x % g != 0 || y % g != 0){
            cout << "N\n";
            continue; 
        }

        if(a == 0 || b == 0){
            cout << "Y\n";
            continue;
        }

        ll xg = x / g, yg = y / g;
        if((xg + yg) % 2 == 0){
            cout << "Y\n";
        }else{
            cout << "N\n";
        }
    }
    return 0;
}