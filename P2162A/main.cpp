#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int q = a[0];
        for(int j = 0; j < n; j++){
            if(q < a[j]){
                q = a[j];
            }
        }
        cout << q << endl;
    }
    return 0;
}