#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[110];
int score = 0;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        score += 100 / a[i] * b[i];
    }
    int t;
    cin >> t;
    if(t <= score){
        cout << "Already Au." << endl;
        return 0;
    }
    int p = t - score;
    for(int i = 1; i <= n; i++){
        if(a[i] == b [i]){
            cout << "NaN" << endl;
            continue;
        }
        if(100 / a[i] * (a[i] - b[i] ) < p){
            cout << "NaN" << endl;
            continue;
        }
        if(a[i] * p % 100 == 0){
            cout << a[i] * p / 100 << endl;

        }else{
            cout << a[i] * p / 100 + 1 << endl;
        }
    }
    return 0;
}
