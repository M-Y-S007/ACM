/*#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int grid[10][10];
int f[20][20][20];

int main(){

    int N;
    cin >> N;
    memset(grid, 0, sizeof(grid));
    int x, y, v;
    while(cin >> x >> y >> v, x || y || v){
        grid[x][y] = v;
    }

    memset(f, 0, sizeof(f));
    for(int k = 2; k <= 2 * N; k++){
        for(int x1 = 1; x1 <= N; x1++){
            for(int x2 = 1; x2 <= N; x2++){
                int y1 = k - x1, y2 = k - x2;
                if(y1 < 1 || y1 > N || y2 < 1|| y2 > N)continue;

                int add = grid[x1][y1];
                if(x1 != x2) add += grid[x2][y2];

                f[k][x1][x2] = max({
                    f[k-1][x1][x2],
                    f[k-1][x1-1][x2],
                    f[k-1][x1][x2-1],
                    f[k-1][x1-1][x2-1]
                }) +add;
            }
        }
    }

    cout << f[2*N][N][N] <<endl;
    return 0;
}*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10][10];
int dp[20][10][10];
int main(){

    int N;
    cin >> N;
    memset(a, 0, sizeof(a));
    int x, y, v;
    while(cin >> x >> y >> v, x || y || v){
        a[x][y] = v;
    }
    memset(dp, 0, sizeof(dp));
    for(int k = 2; k <= 2 * N; k++){
        for(int x1 = 1; x1 <= N; x1++){
            for(int x2 = 1; x2 <= N; x2++){
                int y1 = k - x1, y2 = k - x2;
                if(y1 < 1 || y1 > N || y2 < 1 || y2 > N){
                    continue;
                }
                int sum = a[x1][y1];
                if(x1 != x2){
                    sum += a[x2][y2];
                }
                dp[k][x1][x2] = max({
                    dp[k-1][x1][x2],
                    dp[k-1][x1][x2-1],
                    dp[k-1][x1-1][x2],
                    dp[k-1][x1-1][x2-1]
                }) + sum;
            }
        }
    }
    cout << dp[2*N][N][N];

    return 0;
}