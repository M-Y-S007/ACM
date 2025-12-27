#include<bits/stdc++.h>
using namespace std;
int cnt =0;
int queen[20];
bool col[20];
bool diag1[40];
bool diag2[40];

void dfs(int row, int n){
    if(row > n){
        cnt++;
        if(cnt <= 3){
            for(int i = 1; i <= n; i++){
                cout << queen[i];
                if(i < n) cout << " ";
            }
            cout << endl;
        }
        return;
    }
    for(int c = 1; c <= n; c++){
        if(!col[c] && !diag1[row - c + n] && !diag2[row + c]){
            queen[row] = c;
            col[c] = true;
            diag1[row - c + n] = true;
            diag2[row + c] = true;

            dfs(row + 1, n);

            col[c] = false;
            diag1[row - c + n] = false;
            diag2[row + c] = false;
        }
    }

}
int main(){
    int n;
    cin >> n;
    memset(col, 0, sizeof(col));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));
    dfs(1,n);
    cout << cnt << endl;
    return 0;
}