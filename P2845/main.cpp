#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;

int N, M;
vector<pair<int, int>> switches[maxn][maxn];

bool lit[maxn][maxn];
bool visited[maxn][maxn];
bool inQueue[maxn][maxn];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        switches[a][b].push_back({c, d});
    }

    lit[1][1] = true;

    queue<pair<int, int>> q;

    q.push({1, 1});
    visited[1][1] = true;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
    

    for(auto& [nx, ny] : switches[x][y]){
        if(!lit[nx][ny]){
            lit[nx][ny] = true;

            for(int d = 0; d < 4; d++){
                int ax = nx + dx[d];
                int ay = ny + dy[d];

                if(ax >= 1 && ax <= N && ay <= N && ay >= 1 && visited[ax][ay]){
                    if(!visited[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                    break;
                }
            }
        }
        
    }
    for(int d = 0; d < 4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];

        if(nx >= 1 && nx <= N && ny >= 1 && ny <= N){
            if(!visited[nx][ny] && lit[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    }

    int count = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(lit[i][j]) count ++;
        }
    }

    cout << count << endl;
    return 0;
    
}

/*// 修正后的代码：
#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;

int N, M;
vector<pair<int, int>> switches[maxn][maxn];

bool lit[maxn][maxn];
bool visited[maxn][maxn];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        switches[a][b].push_back({c, d});
    }

    lit[1][1] = true;

    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        // 1. 打开这个房间能控制的所有灯
        for(auto& [nx, ny] : switches[x][y]){
            if(!lit[nx][ny]){
                lit[nx][ny] = true;

                // 检查新点亮的房间是否相邻于已访问区域
                // 需要检查所有四个方向！
                bool canReach = false;
                for(int d = 0; d < 4; d++){
                    int ax = nx + dx[d];
                    int ay = ny + dy[d];

                    if(ax >= 1 && ax <= N && ay >= 1 && ay <= N && visited[ax][ay]){
                        canReach = true;
                        break;  // 这里可以break，因为只要有一个相邻已访问就行
                    }
                }
                
                // 如果可达且未访问，加入队列
                if(canReach && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        
        // 2. 尝试向四个方向移动
        for(int d = 0; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx >= 1 && nx <= N && ny >= 1 && ny <= N){
                if(!visited[nx][ny] && lit[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    // 统计亮的房间数
    int count = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(lit[i][j]) count++;
        }
    }

    cout << count << endl;
    return 0;
}*/