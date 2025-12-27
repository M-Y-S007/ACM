#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
bool isPrime(ll n){
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(ll i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0) return false;

    }
    return true;
}

void solve(){
    vector<ll> results;
    if(a <= 5 && 5 <= b) results.push_back(5);
    if(a <= 7 && 7 <= b) results.push_back(7);

    if(a <= 11 && 11 <= b) results.push_back(11);


    for(ll d1 = 1; d1 <= 9; d1 += 2){
        for(ll d2 = 0; d2 <= 9; d2++){
            ll num = 100 * d1 + 10 * d2 + d1;
            if(num > b) break;
            if(num >= a && isPrime(num)) results.push_back(num);

        }
        for(ll d2 = 0; d2 <= 9; d2++){
            for(ll d3 = 0; d3 <= 9; d3++){
                ll num = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
                if(num < a) continue;
                if(num > b) break;
                if(isPrime(num)) results.push_back(num);
            }
        }
        for(ll d2 = 0; d2 <= 9; d2++){
            for(ll d3 = 0; d3 <= 9; d3++){
                for(ll d4 = 0; d4 <= 9; d4++){
                    ll num = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
                    if(num < a) continue;
                    if(num > b) break;
                    if(isPrime(num)) results.push_back(num);

                }
            }
        }

    }
    sort(results.begin(), results.end());

    for(ll num : results){
        cout << num << "\n";
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    if(b > 10000000) b = 10000000;
    solve();
    return 0;
}