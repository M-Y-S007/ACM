#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, sum;
    cin >> n >> sum;

    int coeff[15] = {1};
    for(int i = 1; i < n; i++){
        coeff[i] = coeff[i - 1] * (n - i) / i;
    }

    vector<int> perm(n);
    for(int i = 0; i < n; i++){
        perm[i] = i + 1;
    }
    do{
        int total = 0;
        for(int i = 0; i < n; i++){
            total += coeff[i] * perm[i];
        }
        if(total == sum){
            for(int i = 0; i < n; i++){
                cout << perm[i] << " ";
            }
            cout << "\n";
            return 0;
        }
    }while(next_permutation(perm.begin(), perm.end()));
    return 0;
}