#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    unordered_set<string> students;
    unordered_set<string> called;
    for(long long i = 0; i < n; i++){
        string name;
        cin >> name;
        students.insert(name);
    }
    long long m;
    cin >> m;
    for(int j = 0; j < m; j++){
        string s;
        cin >> s;
        if(students.find(s) == students.end()){
            cout << "WRONG" << endl;
        }else{
            if(called.find(s) == called.end()){
                cout << "OK" << endl;
                called.insert(s);
            }else{
                cout << "REPEAT" << endl;
            }

        }
    }
    return 0;
}