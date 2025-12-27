#include<bits/stdc++.h>
using namespace std;
int a[10][10];
bool row[10][10];
bool col[10][10];
bool block[10][10];
int getBlock(int i, int j){
    return ((i - 1) / 3) * 3 + ((j - 1) / 3) + 1;
}
bool dfs(int i, int j){
    if(i > 9) return true;
    if(j > 9) return dfs(i + 1, 1);
    if(a[i][j] != 0) return dfs(i, j + 1);

    int k = getBlock(i, j);
    for(int num = 1; num <= 9; num++){
        if(!row[i][num] && !col[j][num] && !block[k][num]){
            a[i][j] = num;
            row[i][num] = true;
            col[j][num] = true;
            block[k][num] = true;
            if(dfs(i, j + 1)) return true;

            a[i][j] = 0;
            row[i][num] = false;
            col[j][num] = false;
            block[k][num] = false;
        }
    }
    return false;

}
int main(){
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(block, 0, sizeof(block));
    for(int i = 1; i <= 9; i++){
        
        for(int j = 1; j <= 9; j++){
            cin >> a[i][j];
            if(a[i][j] != 0){
                int num = a[i][j];
                int k = getBlock(i, j);
                row[i][num] = true;
                col[j][num] = true;
                block[k][num] = true;
            }
        }
    }
    dfs(1, 1);

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}