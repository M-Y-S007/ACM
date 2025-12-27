#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll segmentedSieve(ll l, ll r){
    if( r < 2) return 0;

    l = max(l, 2LL);

    ll limt = sqrt(r) + 1;
    vector<bool> isPrimeSmall(limt + 1, true);
    vector<ll> primes;

    for(ll i = 2; i <= limt; i++){
        if(isPrimeSmall[i]){
            primes.push_back(i);
            for(ll j = i * i; j <= limt; j += i){
                isPrimeSmall[j] = false;
            }
        }
    }

    vector<bool> isPrimeRange(r - l + 1, true);
    for(ll p : primes){
        ll start = max(p * p, ((l + p - 1) / p) * p);

        for(ll j = start; j <= r; j += p){
            isPrimeRange[j - l] = false;
        }
    }

    ll cnt = 0;
    for(ll i = 0; i < isPrimeRange.size(); i++){
        if(isPrimeRange[i]){
            cnt++;
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll l, r;
    cin >> l >> r;
    
    cout << segmentedSieve(l, r) << endl;
    
    return 0;
}