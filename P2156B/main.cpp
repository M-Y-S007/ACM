#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, q;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> q;
        cin >> s;
        
        int arr[q];
        for(int k = 0; k < q; k++){
            cin >> arr[k];
        }
        for(int k = 0; k < q; k++){
            int time = 0;
            int pos = 0;
            int current = arr[k];
            
            while(current > 0){
                if(s[pos] == 'A'){
                    current -= 1;
                } else {
                    current /= 2;
                }
                time++;
                
                if(current == 0) break;
                
                pos = (pos + 1) % n;
            }
            cout << time << " ";
        }
        cout << endl;
    }
    return 0;
}