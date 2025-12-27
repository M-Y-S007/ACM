#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[300005];
ll p[300005];
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int j = 0; j < m; j++){
        cin >> p[j];
    }
    ll g = 0;
    for(int i = 1; i < n; i++){
        g = gcd(g, x[i] - x[0]);
    }

    for(int i = 0; i < m; i++){
        if(g % p[i] == 0){
            cout << "YES" << endl;
            cout << x[0] << " " <<  i + 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}