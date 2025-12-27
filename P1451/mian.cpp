#include<bits/stdc++.h>
using namespace std;
int n, m;
char cell[110][110];
int cnt = 0;
int dx[4] = {1, -1, 0 , 0};
int dy[4] = {0, 0 , -1, 1};
void dfs(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m){
        return;
    }
    if(cell[x][y] != '0'){
        cell[x][y] = '0';
        for(int i = 0; i < 4; i++){
            dfs(x + dx[i], y + dy[i]);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> cell[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(cell[i][j] != '0'){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}