#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> parent(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> parent[i];
    }

    int maxdepth = 0;
    for(int i = 1; i <= n; i++){
        int depth = 0;
        int current = i;

        while(current != -1){
            depth++;
            current = parent[current];
        }

        maxdepth = max(maxdepth, depth);
    }
    cout << maxdepth << endl;
    return 0;
}