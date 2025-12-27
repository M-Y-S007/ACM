#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    map<int, deque<int>> deques;
    while(q--){
        string s;
        cin >> s;
        if(s == "push_back"){
            int a,x;
            cin >> a >> x;
            deques[a].push_back(x);
        }else if(s == "pop_back"){
            int a;
            cin >> a;
            if(!deques[a].empty()){
                deques[a].pop_back();}
        }else if(s == "push_front"){
            int a,x;
            cin >> a >> x;
            deques[a].push_front(x);
        }else if(s == "pop_front"){
            int a;
            cin >> a;
            if(!deques[a].empty()){
                deques[a].pop_front();
            }
        }else if(s == "size"){
            int a;
            cin >> a;
            cout << deques[a].size() << endl;
        }else if(s == "front"){
            int a;
            cin >> a;
            if(!deques[a].empty()){
                cout << deques[a].front() << endl;
            }
        }else{
            int a;
            cin >> a;
            if(!deques[a].empty()){
                cout << deques[a].back() << endl;
            }
        }
    }
    return 0;
}