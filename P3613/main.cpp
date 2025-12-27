#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    map<pair<int, int>, int> locker;
    while(q--){
        int op,i,j;
        cin >> op >> i >> j;
        if(op == 1){
            int k;
            cin >> k;
            if(k == 0){
                locker.erase({i, j});
            }else{
                locker[{i, j}] = k;

            }
        }else{
            cout << locker[{i,j}] <<endl;
        }
    }
    return 0;
}