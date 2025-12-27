#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    queue<int> queues;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        if(k == 1){
            int x;
            cin >> x;
            queues.push(x);
        }else if(k == 2){
            if(!queues.empty()){
                queues.pop();
            }else{
                cout << "ERR_CANNOT_POP" << endl;
            }
        }else if(k == 3){
            if(!queues.empty()){
                cout << queues.front() << endl;
            }
            else cout << "ERR_CANNOT_QUERY" << endl;
        }else{
            cout << queues.size() << endl;
        }
    }
    return 0;
}