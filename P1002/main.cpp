#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, horse_x, horse_y;
    cin >> n >> m >> horse_x >> horse_y;

    vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
    int dx[] = {0, -2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {0, -1, 1, -2, 2, -2, 2, -1, 1};

    vector<vector<bool>> control(n+1, vector<bool>(m+1, false));

    for(int i = 0; i < 9; i++){
        int x = horse_x + dx[i];
        int y = horse_y + dy[i];
        if(x >= 0 && x <= n && y >= 0 && y <= m){
            control[x][y] = true;
        }
    }

    if(!control[0][0]){
        dp[0][0] = 1;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if((i == 0 && j == 0) || control[i][j]){
                continue;
            }
            if(i > 0 && !control[i - 1][j]){
                dp[i][j] += dp[i - 1][j];
            }

            if(j > 0 && !control[i][j - 1]){
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    
    cout << dp[n][m] << endl;
    return 0;
}