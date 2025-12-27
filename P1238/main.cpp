#include<bits/stdc++.h>
using namespace std;
int a[20][20];

int main(){
    int m, n;
    int start_x, start_y;
    int end_x, end_y;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cin >> start_x >> start_y;
    cin >> end_x >> end_y;
    return 0;
}