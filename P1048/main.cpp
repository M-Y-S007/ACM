#include<bits/stdc++.h>
using namespace std;
const int MAX_M = 110;
const int MAX_T = 1010;
int T, M;
int dp[MAX_M][MAX_T];
int cost[110];
int price[110];
void solve(){
    for(int j = 0; j <= T; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= M; i++){
        for(int j = 0; j <= T; j++){
            if(j < cost[i]){
            dp[i][j] = dp[i - 1][j];
            }else{
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + price[i]);
            }
        }
    }
    cout << dp[M][T];
}
int main(){
    cin >> T >> M;
    for(int i = 1; i <= M; i++){
        cin >> cost[i] >> price[i];
    }
    solve();
    return 0;
}