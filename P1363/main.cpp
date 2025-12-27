#include<bits/stdc++.h>
using namespace std;
const int maxn = 1505;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int vis_x[maxn][maxn];
int vis_y[maxn][maxn];

int n, m;


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool bfs(int start_x,int start_y){
    memset(vis, 0, sizeof(vis));
    memset(vis_x, -1, sizeof(vis_x));
    memset(vis_y, -1, sizeof(vis_y));

    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    vis[start_x][start_y] = true;
    vis_x[start_x][start_y] = start_x;
    vis_y[start_x][start_y] = start_y;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            int rx = ((nx % n) + n) % n;
            int ry = ((ny % m) + m) % m;

            if(maze[rx][ry] == '#') continue;

            if(!vis[rx][ry]){
                vis[rx][ry] = true;
                vis_x[rx][ry] = nx;
                vis_y[rx][ry] = ny;
                q.push({nx, ny});
            }
            else if(vis_x[rx][ry] != nx || vis_y[rx][ry] != ny){
                return true;
            }
        }
    }
    return false;
}
int main(){
    while(cin >> n >> m){
        int start_x, start_y;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> maze[i][j];
                if(maze[i][j] == 'S'){
                    start_x = i;
                    start_y = j;
                }
            }
        }
        if(bfs(start_x, start_y)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }

    }

    return 0;
}