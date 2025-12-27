#include<bits/stdc++.h>
using namespace std;
long long solve(long long n){
    long long t = sqrt(n);
    return t - (t * t == n);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int  t;
    long long n;
    cin >> t;
    for(int j = 0; j < t; j++){
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}