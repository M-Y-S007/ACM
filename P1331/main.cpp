#include<bits/stdc++.h>
using namespace std;
int R, C;
char dist[1010][1010];
bool vis[1010][1010];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int x, int y){
    if(x < 1 || x > R || y < 1 || y > C){
        return;
    }
    if(dist[x][y] != '#' || vis[x][y]){
        return;
    }

    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
        dfs(x + dx[i], y + dy[i]);
    }
}
int main(){
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> dist[i][j];
        }
    }
    for(int i = 1; i < R; i++){
        for(int j = 1; j < C; j++){
            int cnt = 0;
            if(dist[i][j] == '#') cnt++;
            if(dist[i + 1][j] == '#') cnt++;
            if(dist[i][j + 1] == '#') cnt++;
            if(dist[i + 1][j + 1] == '#') cnt++;

            if(cnt == 3){
                cout << "Bad placement." << "\n";
                return 0;
            }
        }
    }
    int S = 0;
    memset(vis, false, sizeof(vis));

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(dist[i][j] == '#' && !vis[i][j]){
                S++;
                dfs(i, j);
            }
        }
    }

    cout << "There are " << S << " ships." << "\n";
    return 0;
}