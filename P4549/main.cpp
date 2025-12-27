#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[25];
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    int n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> num[i];
    }
    ll g = gcd(num[1], num[2]);
    for(ll j = 3; j <= n; j++){
        g = gcd(g, num[j]);
    }
    if(g < 0){
        g = -g;
    }
    cout << g << endl;
}