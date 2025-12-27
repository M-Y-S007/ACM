#include<bits/stdc++.h>
using namespace std;
int n, m;
char dist[1510][1510];
int cnt = 0;
int dx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int star_num;
int num[100005];
bool cmp(int a, int b){
    return a > b; 
}
void dfs(int x, int y){
    if(dist[x][y] == '.'){
        return;
    }
    if(x < 1 || x > n || y < 1 || y > m){
        return;
    }
    if(dist[x][y] == '*'){
        star_num++;
        dist[x][y] = '.';
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(dist[nx][ny] == '*'){
                dfs(nx, ny);
            }
        }
    }

}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j= 1; j <= m; j++){
            cin >> dist[i][j];
        }
    }
    memset(num, 0, sizeof(num));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dist[i][j] == '*'){
                star_num = 0;
                dfs(i, j);
                num[star_num] += star_num;
            }
        }
    }
    sort(num, num + 100005, cmp);
    int cnt = 0;
    int ans = num[0];
    for(int i = 0; num[i] != 0; i++){
        cnt ++;
    }
    cout << cnt << " " << ans;
    return 0;
}