#include<bits/stdc++.h>
using namespace std;
int a[100];
int cnt;
void dfs(int n, int last){
    if(n == 0){
        if(cnt > 1){
        for(int i = 1; i <= cnt; i++){
            cout << a[i];
            if(i < cnt) cout << "+";
        }
        cout << endl;
        }
        return;
    }
    for(int i = last; i <= n; i++ ){
        cnt++;
        a[cnt] = i;
        dfs(n - i, i);
        cnt--;
    }
}
int main(){
    int n;
    cin >> n;
    cnt = 0;
    dfs(n, 1);
    return 0;
}