#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e6 + 10;

int n, p, k;
int a[N];
ll pre[N];      // 前缀积 pre[i] = a[1]*a[2]*...*a[i]
ll inv_pre[N];  // 前缀积的逆元

ll qpow(ll a, ll b, ll p){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    // 使用scanf/printf加速
    scanf("%d%d%d", &n, &p, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    
    // 1. 计算前缀积
    pre[0] = 1;
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] * a[i] % p;
    }
    
    // 2. 求整体逆元
    inv_pre[n] = qpow(pre[n], p - 2, p);
    
    // 3. 倒推得到每个前缀积的逆元
    for(int i = n; i >= 1; i--){
        // inv_pre[i-1] = inv_pre[i] * a[i] % p
        inv_pre[i-1] = inv_pre[i] * a[i] % p;
    }
    
    // 4. 计算答案
    ll ans = 0;
    ll k_pow = 1;  // k^0 = 1
    
    for(int i = 1; i <= n; i++){
        k_pow = k_pow * k % p;  // k^i
        
        // a[i]的逆元 = inv_pre[i] * pre[i-1] % p
        ll inv_ai = inv_pre[i] * pre[i-1] % p;
        
        ans = (ans + k_pow * inv_ai) % p;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}