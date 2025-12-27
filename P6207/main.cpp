#include<bits/stdc++.h>
using namespace std;
int r, c;
char dist[120][80];
bool visited[120][80];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
pair<int, int> parent[120][80];

void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();

        if(x == r && y == c){
            vector<pair<int, int>> path;
            int cx = x, cy = y;
            while(cx != 0 && cy != 0){
                path.push_back({cx, cy});
                auto[px, py] = parent[cx][cy];
                cx = px;
                cy = py;
            } 
            reverse(path.begin(), path.end());
            for(auto [px, py] : path){
                cout << px << " " << py << "\n";
            }
            return;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && nx <= r && ny >= 1 && ny <= c && 
            !visited[nx][ny] && dist[nx][ny] == '.'){
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> dist[i][j];
        }
    }

    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    bfs(1, 1);
    return 0;
}