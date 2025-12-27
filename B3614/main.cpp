#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        stack<int> q;
        for(int j = 0; j < n; j++){
            string s;
            cin >> s;
            if(s == "push"){
                int x;
                cin >> x;
                q.push(x);
            }else if(s == "pop"){
                if(!q.empty()){
                    q.pop();
                }else{
                    cout << "Empty" << endl;
                }
            }else if(s == "query"){
                if(!q.empty()){
                    cout << q.top() << endl;
                }else{
                    cout << "Anguei!" << endl;
                }
            }else{
                cout << q.size() << endl;
            }
        }
    }
    return 0;
}