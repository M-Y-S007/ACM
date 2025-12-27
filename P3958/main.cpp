#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point{
    ll x, y, z;
};

int T, n, h, r;
Point holes[1010];
bool visited[1010];

ll dist2(const Point&a, const Point&b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    ll dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}
bool bfs(){
    memset(visited, false, sizeof(visited));
    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(holes[i].z <= r){
            q.push(i);
            visited[i] = true;
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(holes[cur].z >= h - r){
            return true;
        }

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                ll d2 = dist2(holes[cur], holes[i]);
                ll limt = 4LL * r * r;
                if(d2 <= limt){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    return false;
}
int main(){
    cin >> T;
    while(T--){
        cin >> n >> h >> r;
        for(int i = 1; i <= n; i++){
            cin >> holes[i].x >> holes[i].y >> holes[i].z;

        }
        if(bfs()){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << "\n";
        }
    }
    return 0;
}