#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;
int graph[35][35];
void dfs(int x, int y){
    if(x < 1 || x > n || y < 1 || y > n){
        return;
    }
    if(graph[x][y] != 0){
        return;
    }
    graph[x][y] = 3;
    for(int i = 0; i < 4; i++){
        int x0 = x + dx[i];
        int y0 = y + dy[i];
        if(graph[x0][y0] == 0){
            graph[x0][y0] = 3;
            dfs(x, y);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        if(graph[1][i] == 0)dfs(1, i);
        if(graph[n][i] == 0)dfs(n, i);
        if(graph[i][1] == 0)dfs(i, 1);
        if(graph[i][n] == 0)dfs(i, n);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == 0){
                cout << 2 << " ";
            }
            if(graph[i][j] == 1){
                cout << 1 << " ";
            }
            if(graph[i][j] == 3){
                cout << 3 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}


/*#include<bits/stdc++.h>
using namespace std;
const int maxn = 35;
int val[maxn][maxn];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
void dfs(int x, int y){
    if(x > n || y > n || x < 1 || y < 1){
        return;
    }
    if(val[x][y] != 0) return;

    val[x][y] = 3;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny);
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> val[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        if(val[1][i] == 0) dfs(1, i);
        if(val[n][i] == 0) dfs(n, i);
        if(val[i][1] == 0) dfs(i, 1);
        if(val[i][n] == 0) dfs(i, n);

    }
    for(int i =1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(val[i][j] == 0){
                cout << 2;
            } else if(val[i][j] == 3){
                cout << 0;
            }else{
                cout << 1;
            }
            if(j < n) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}*/