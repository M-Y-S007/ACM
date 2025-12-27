#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll t;
    scanf("%lld",&t);
    for(ll i = 0;i < t; i++){
    ll a, b, c, x0, y0;
    ll x_max, x_min, y_max, y_min;
    ll k1, k2;
    scanf("%lld%lld%lld",&a, &b, &c);  
    ll g = gcd(a, b);
    exgcd(a, b, x0, y0);
    if(c % gcd(a, b) != 0){
        cout << -1 << endl;
        continue;
    }else if(-c / b * x0 <= c / a * y0 + 2){
        if(c * y0 % a == 0){
            k1 = c * y0 / a - 1;
            x_max = c / g * x0 + b / g * k1;
            y_min = c / g * y0 - a / g * k1;
        }else{
            k1 = c * y0 / a;
            x_max = c / g * x0 + b / g * k1;
            y_min = c / g * y0 - a / g * k1;       
        }

        if(c * x0 % b == 0){
            k2 = 1 - c * x0 / b;
            x_min = c / g * x0 + b / g * k2;
            y_max = c / g * y0 - a / g * k2;    
        }else{
            k2 = - c * x0 / b;
            x_min = c / g * x0 + b / g * k2;
            y_max = c / g * y0 - a / g * k2;
        }
        printf("%lld %lld %lld %lld\n",x_min, y_min, x_max, y_max);

    }else{
        if(c * x0 % b == 0){
            k1 = 1 - c * x0 / b;
            x_min = c / g * x0 + b / g * k1;
        }else{
            k1 = - c * x0 / b;
            x_min = c / g * x0 + b / g * k1;
        }
        if(c * y0 % a == 0){
            k2 = c * y0 / a - 1;
            y_min = c / g * y0 - a / g * k2;
        }else{
            k2 = c * y0 / a;
            y_min = c / g * y0 - a / g * k2;
        }
        printf("%lld %lld\n",x_min, y_min);
    }
    
    }
    return 0;
}