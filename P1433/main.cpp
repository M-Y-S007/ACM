#include<bits/stdc++.h>
using namespace std;
int n;
double x[20], y[20];
double dist[20][20];
double dp[1 << 16][20];

double calc_dist(int i, int j){
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

}
int main(){

    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%lf%lf",&x[i], &y[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = calc_dist(i, j);
        }
    }

    for(int S = 0; S < (1 << n); S++){
        for(int i = 0; i < n; i++){
            dp[S][i] = 1e20;
        }
    }

    for(int i = 0; i < n; i++){
        dp[1 << i][i] = sqrt(x[i] * x[i] + y[i] * y[i]);
    }

    for(int S = 1; S < (1 << n); S++){
        for(int i = 0; i < n; i++){
            if(!(S >> i & 1)) continue;

            for(int j = 0; j < n; j++){
                if(S >> j & 1)continue;
                int newS = S | (1 << j);
                dp[newS][j] = min(dp[newS][j], dp[S][i] + dist[i][j]);
            }
        }
    }
    double ans = 1e20;
    int full = (1 << n) - 1;
    for(int i = 0; i < n; i++){
        ans = min(ans, dp[full][i]);
    }

    printf("%.2lf\n",ans);
    return 0;
}