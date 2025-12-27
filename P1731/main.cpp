#include<bits/stdc++.h>
using namespace std;
int n, m;
int h[20];
int r[20];
int sum = 0;
void bfs(){

    for(int i = m; ; i++){
        for(int j = m; ; j++){
            r[1] = i;
            h[1] = j;
            sum += r[1] * r[1] + r[1] * h[1];
        }
    }

}
int main(){
    cin >> n >> m;
    return 0;
}
// S_surface / pi = r1 * r1 + 2 * (ri * hi)
