#include<bits/stdc++.h>
using namespace std;
int k[205];
int dist[205];
int n, a, b;
int bfs(){
    memset(dist, -1, sizeof(dist));
    queue<int> q;

    dist[a] = 0;
    q.push(a);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        if(current == b){
            return dist[current];
        }

        int up = current + k[current];
        if(up >= 1 && up <= n && dist[up] == -1){
            dist[up] = dist[current] + 1;
            q.push(up);
        }
        int down = current - k[current];
        if(down >= 1 && down <= n && dist[down] == -1){
            dist[down] = dist[current] + 1;
            q.push(down);
        }
    }
    return -1;
}
int main(){

    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        cin >> k[i];
    }
    int result = bfs();
    cout << result << endl;
    return 0;
}