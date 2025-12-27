#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j = 1; j <= n; j++){
            cin >> a[j];
        }
        sort(a + 1, a + 1 + n);
        int x;
        cin >> x;
        if((a[1] <= x) && (a[n] >= x)){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}