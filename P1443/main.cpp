#include<bits/stdc++.h>
using namespace std;
int dx[10] = {0,1,1,-1,-1,2,2,-2,-2};
int dy[10] = {0,2,-2,2,-2,1,-1,1,-1};
int d[405][405];
int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            d[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    d[x][y] = 0;
    q.push({x, y});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i = 1; i <= 8; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx >= 1 && nx <=n && ny >= 1 && ny <= m && d[nx][ny] == -1){
                d[nx][ny] = d[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << d[i][j];
                if(j < m) cout << " ";
            }
            cout << "\n";
        }
    
    return 0;
}