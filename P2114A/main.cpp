#include<bits/stdc++.h>
using namespace std;
int k;
bool IsSquare(string s){
    double t = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
    for(int i = 0; i <= sqrt(t); i++){
        if(i * i == t){
            k = i;
            return true;
        }
        
    }
    return false;
}
int main(){
    int t;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> s;
    
    if(IsSquare(s)){
        cout << 0 << " " << k << endl;
    }
    else{
        cout << -1 << endl;
    }
    }
    return 0;
}
