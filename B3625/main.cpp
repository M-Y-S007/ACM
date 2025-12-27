#include<bits/stdc++.h>
using namespace std;
int n, m;
char dist[110][110];
bool visited[110][110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m){
        return;
    }
    if(dist[x][y] == '#'){
        return;
    }
    if(x == n && y == m){
        cout << "Yes" << "\n";
        exit(0);
    }
    for(int i = 0;  i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!visited[nx][ny] && nx > 0 && nx <= n && ny > 0 && ny <= m){
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> dist[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    visited[1][1] = true;
    dfs(1, 1);
    cout << "No" << "\n";
    return 0;
}