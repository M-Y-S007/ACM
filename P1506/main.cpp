#include<bits/stdc++.h>
using namespace std;
int x, y;
char dist[510][510];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt = 0;
void dfs(int x0, int y0){
    if(x0 < 1 || x0 > x || y0 < 1 || y0 > y){
        return;
    }
    if(dist[x0][y0] == '0'){
        dist[x0][y0] = '1';
        for(int i = 0; i < 4; i++){
            dfs(x0 + dx[i], y0 + dy[i]);
        }
    }else{
        return;
    }
    
}
int main(){
    cin >> x >> y;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            cin >> dist[i][j];
        }
    }
    for(int i = 1; i <= x; i++){
        dfs(i, 1);
        dfs(i, y);
    }
    for(int i = 1; i <= y; i++){
        dfs(1, i);
        dfs(x, i);
    }
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if(dist[i][j] == '0'){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}