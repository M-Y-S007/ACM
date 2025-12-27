#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector <int> a(n);
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        bool found = false;
        for(int k = 0; k < n && !found; k++){
            for(int l = k + 1; l < n && !found; l++){
                if((a[l] % a[k]) % 2 == 0){
                    cout << a[k] << " " << a[l] << "\n";
                    found = true;
                }
            }
        }
        if(!found){
            cout << -1 << "\n";
        }
    }

    return 0;
}