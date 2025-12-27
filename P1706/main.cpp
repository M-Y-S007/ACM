#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        a[i] = i + 1;
    }
    do{
        for(int num : a){
            cout << "    " << num;
        }
        cout << endl;
    }while(next_permutation(a.begin(), a.end()));
    return 0;
}