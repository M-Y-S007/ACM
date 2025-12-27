#include<iostream>
using namespace std;
int n, m, q, a[1000005];

int find(int q){
    int l = 0, r = n + 1;
    while(l + 1 < r){
        int mid = l + r >> 1;
        if(a[mid] >= q){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return a[r] == q ? r : -1; 
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> q;
        cout << find(q) << ' ';
    }
    return 0;
}