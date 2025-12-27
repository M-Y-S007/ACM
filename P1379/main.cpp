#include<bits/stdc++.h>
using namespace std;
const string TARGET = "123804765";

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(string start){
    if(start == TARGET){
        return 0;
    }

    unordered_map<string, int> dist;
    queue<string> q;

    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        string cur = q.front();
        q.pop();

        int pos = cur.find('0');
        int x = pos / 3;
        int y = pos % 3;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
                int npos = nx * 3 + ny;
                string next = cur;
                swap(next[pos], next[npos]);

                if(dist.find(next) == dist.end()){
                    dist[next] = dist[cur] + 1;
                    if(next == TARGET){
                        return dist[next];
                    }
                    q.push(next);
                }
            }
        }
    }
    return -1;
}
int main(){
    string start;
    cin >> start;
    cout << bfs(start) << "\n";
    return 0;
}