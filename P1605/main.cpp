#include<bits/stdc++.h>
using namespace std;
int n, m, t;
int sx, sy, fx, fy;
int maze[10][10];
int ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int x, int y){
    if(x == fx && y == fy){
        ans++;
        return;
    }

    for(int i = 0; i <4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || nx > n || ny <1 || ny > m){
            continue;
        }

        if(maze[nx][ny] == 0){
            maze[nx][ny] = 2;

            dfs(nx, ny);

            maze[nx][ny] = 0;
        }
    }
}
int main(){
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    memset(maze, 0, sizeof(maze));

    for(int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;
        maze[x][y] = 1;
    }
    if(maze[fx][fy] == 1){
        cout << 0 << endl;
        return 0;
    }

    maze[sx][sy] = 2;

    dfs(sx, sy);
    cout << ans << endl;
}