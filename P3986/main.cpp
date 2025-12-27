#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll k;
    cin >> k;
    
    // 生成斐波那契数列直到 F_n > k
    vector<ll> F = {0, 1};
    while (F.back() <= k) {
        F.push_back(F.back() + F[F.size()-2]);
    }
    
    ll ans = 0;
    
    for (int n = 2; n < (int)F.size(); n++) {
        ll x = F[n-1], y = F[n];
        
        if (k % __gcd(x, y) != 0) continue; // 实际上gcd=1，但保留检查
        
        ll u, v;
        exgcd(x, y, u, v); // x*u + y*v = 1
        
        // 特解 a0 = k*u, b0 = k*v
        // 调整 a0 到 [0, y-1] 范围内
        ll a0 = (k % y) * (u % y) % y;
        a0 = (a0 + y) % y; // 现在 a0 在 [0, y-1]
        
        // 计算对应的 b0 = (k - x*a0)/y
        // 检查是否整除
        if ((k - x * a0) % y != 0) continue;
        ll b0 = (k - x * a0) / y;
        
        // 现在通解: a = a0 + y*t, b = b0 - x*t
        // 要求 a >= 1, b >= 1
        // 注意：a0 >= 0，但如果 a0 == 0，需要 a >= 1，所以 t >= 1
        
        ll t_min, t_max;
        
        // 计算 t_min: a0 + y*t >= 1
        if (a0 >= 1) {
            t_min = 0; // a0 已经 >= 1
        } else {
            t_min = 1; // a0 = 0，需要 t >= 1 使 a >= 1
        }
        
        // 计算 t_max: b0 - x*t >= 1 => x*t <= b0-1
        if (b0 >= 1) {
            t_max = (b0 - 1) / x;
        } else {
            t_max = -1; // 无解
        }
        
        if (t_min <= t_max) {
            ll cnt = (t_max - t_min + 1) % MOD;
            ans = (ans + cnt) % MOD;
        }
    }
    
    cout << ans << endl;
    return 0;
}