#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e8 + 10;
bitset<N> vis;
int prime[6000000];
int cnt = 0;

void get_prime(int n){
    for(int i = 2; i <= n; i++){
        if(!vis[i]){
            prime[++cnt] = i;
        }
        for(int j = 1;j <= cnt && 1ll * i *prime[j] <= n; j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                break;
            }
        }
    }

}

int main(){
    int q;
    int n;
    scanf("%d%d",&n,&q);
    get_prime(n);
    for(int i = 0; i < q; i++){
        int k;
        scanf("%d",&k);
        printf("%d\n",prime[k]);
    }

}