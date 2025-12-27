#include<bits/stdc++.h>
using namespace std;
int n, m;
typedef __int128 ll;
inline ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void write(ll x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 85;
int n, m;
int a[N][N];
ll pow2[N];
ll dp[N][N];

ll solve_row(int row){
    for(int i = 1; i <= m; i++){
        dp[i][i] = a[row][i] * pow2[m];
    }

    for(int len = 2; len <= m; len++){
        for(int l = 1; l + len - 1 <= m; l++){
            int r = l + len - 1;
            int k = m - len + 1;

            ll left_val = dp[l + 1][r] + (ll)a[row][l] * pow2[k];

            ll right_val = dp[l][r - 1] + (ll)a[row][r] * pow2[k];

            dp[l][r] = max(left_val, right_val);

        }
    }
    return dp[1][m];
}

int main(){
    cin >> n >> m;
    pow2[0] = 1;
    for(int i = 1; i <= m; i++){
        pow2[i] = pow2[i - 1] * 2;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    
    ll total = 0;
    for(int i = 1; i <= n; i++){
        total += solve_row(i);
    }

    write(total);
    putchar('\n');
    return 0;
}