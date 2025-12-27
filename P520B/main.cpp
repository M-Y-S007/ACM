#include<bits/stdc++.h>
using namespace std;
const int maxn = 400000;
int val[maxn];
int bfs(int m, int n){
    if(n > m){
        return n - m;
    }
    if(n == m){
        return 0;
    }
    memset(val, -1, sizeof(val));
    queue<int> q;
    q.push(n);
    val[n] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        int y = 2 * x;
        if(y < maxn && val[y] == -1){
            val[y] = val[x] + 1;
            q.push(y);
        }
        y = x - 1;
        if(y > 1 && val[y] == -1){
            val[y] = val[x] + 1;
            q.push(y);
        }
    }
    return -1;

}
int main(){
    int n, m;
    cin >> n >> m;

    int ans = bfs(n, m);
    cout << ans << endl;

}





































/*#include<bits/stdc++.h>
using namespace std;
const int maxn = 400000;
int dist[maxn];
int bfs(int n, int m){
    if(n == m){
        return 0;
    }
    if(n > m){
        return n - m;
    }
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    dist[n] = 0;
    q.push(n);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        if(a == m){
            return dist[a];
        }
        int next = a * 2;
        if(next < maxn && dist[next] == -1){
            dist[next] = dist[a] + 1;
            q.push(next);
        }
        next = a - 1;
        if(next >= 1 && dist[next] == -1){
            dist[next] = dist[a] + 1;
            q.push(next);
        }

    }
    return -1;
}
int main(){
    int n, m;
    cin >> n >> m;
    int ans = bfs(n, m);
    cout << ans << endl;
    return 0;
}*/