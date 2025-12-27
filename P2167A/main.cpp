#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if((a == b) && (b == c) && (c == d)){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
    
    
    return 0;
}