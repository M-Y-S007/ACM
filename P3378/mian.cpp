#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int> > q;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int op;
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
            q.push(x);
        }else if(op == 2){
            cout << q.top() << endl;
        }else{
            q.pop();
        }
    }
}