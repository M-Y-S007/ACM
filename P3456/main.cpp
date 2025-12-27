#include<bits/stdc++.h>
using namespace std;
int n;
int h[1010][1010];
bool visited[1010][1010];

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> h[i][j];
        }
    }

    int peak = 0, valley = 0;

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                vector<pair<int, int>> component;

                int height = h[i][j];

                while(!q.empty()){
                    auto [x, y] = q.front();
                    q.pop();
                    component.push_back({x, y});

                    for(int d = 0; d < 8; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if(nx >= 0 && nx < n && ny >= 0 && ny < n &&
                        !visited[nx][ny] && h[nx][ny] == height){
                            visited[nx][ny] = true;
                            q.push({nx,ny});
                        }
                    }
                }
                bool is_peak = true;
                bool is_valley = true;

                for(auto&[x, y] : component){
                    for(int d = 0; d < 8; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                            if(h[nx][ny] > height){
                                is_peak = false;

                            }
                            if(h[nx][ny] < height){
                                is_valley = false;
                            }
                        }
                    }
                }
                bool has_lower = false, has_higher = false;
                for(auto&[x, y] : component){
                    for(int d = 0; d < 8; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                            if(h[nx][ny] > height) has_higher = true;
                            if(h[nx][ny] < height) has_lower = true;
                        }
                    }
                }

                if(!has_lower && ! has_higher){
                    peak++;
                    valley++;
                }else{
                    if(is_peak && has_lower) peak++;
                    if(is_valley && has_higher) valley++;
                }
            }
        }
    }

    cout << peak << " " << valley << endl;
    return 0;
}