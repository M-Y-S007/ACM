#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 3e6 + 10;
ll inv[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, p;
    cin >> n >> p;
    
    inv[1] = 1;
    cout << inv[1] << "\n";

    for(int i = 2; i <= n; i++){
        inv[i] = (p - p / i) * inv[p % i] % p;
        cout << inv[i] << "\n";
    }
    return 0;
}