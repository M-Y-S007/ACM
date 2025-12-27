#include<bits/stdc++.h>
using namespace std;
const int MAX = 110;
int r, c;
int h[MAX][MAX];
int dp[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dfs(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];


        if(nx >= 1 && nx <= r && ny >= 1 && ny <= c && h[x][y] > h[nx][ny]){
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
    }
    return dp[x][y];
}
int main(){
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> h[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    
    return 0;
}