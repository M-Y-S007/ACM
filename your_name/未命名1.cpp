#include<bits/stdc++.h>
using namespace std;

int main(){
    int q, n;
    cin >> q;
    
    while(q--){
        cin >> n;
        string s, t;
        cin >> s >> t;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s == t){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
