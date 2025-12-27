#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int A[N], C[N];
int b, la, lc;
void div(int A[], int b, int C[]){
    long long r = 0;
    for(int i = la - 1; ~ i; i--){
        r = r * 10 + A[i];
        C[la - 1 - i] = r / b;
        r %= b;
    }
    reverse(C, C + lc);
    while(lc > 0 && C[lc] == 0) lc--;
}
int main(){
    string a;
    cin >> a >> b;
    lc = la = a.size();
    for(int i = la - 1; ~ i; i--) A[la - 1 - i] = a[i] - '0';
    div(A, b, C);
    for(int i = lc; ~ i; i--) printf("%d", C[i]);
    return 0;
}